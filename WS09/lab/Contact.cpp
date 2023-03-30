/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
#include "Contact.h"
using namespace sdds;
int count = 0; 

Contact& sdds::Contact::operator=(const Contact& contact)
{
	
	if (this != &contact)
	{
		Person::operator=(contact);
		delAlloCopy(m_address, contact.m_address);
		delAlloCopy(m_city, contact.m_city);
		strCpy(m_province, contact.m_province);
		strCpy(m_postalCode, contact.m_postalCode);
	}
	return *this;
}



sdds::Contact::Contact(const Contact& contact) 
{
	operator=(contact);
}



sdds::Contact::~Contact()
{
	~*this;
}

istream& sdds::Contact::read(istream& i)
{
	~*this;
	Person::read(i);
	m_address = dynRead(i, ',');
	m_city = dynRead(i, ',');
	i.getline(m_province,256, ',');
	
	i.get(m_postalCode,256);
	
	
	if (i.fail()) ~*this;
	if (!*this)
	{
		i.setstate(std::ios::failbit);
	}
	
	return i;
}

ostream& sdds::Contact::write(ostream& o) const
{
	Person::write(o);
	using std::endl;
	
	if (count == 0 && *this)
	{
		o << endl << m_address << endl << m_city << " " << m_province << endl; printPostalCode(o, m_postalCode) << endl;
		count++;
	}
	else if (count > 0 && *this)
	{
		o << endl << m_address << endl << m_city << " " << m_province << endl; printPostalCode(o, m_postalCode);
	}
	
	return  o;
}

sdds::Contact::operator bool() const
{
	return Person::operator bool() && m_address && m_address[0] && m_city && m_city[0] && m_postalCode[0] && strLen(m_postalCode) == 6 && m_province[0] && strLen(m_province) == 2;
}

void sdds::Contact::operator~()
{
	Person::operator~();
	delete[] m_address;
	delete[] m_city;
	m_address = m_city = nullptr;
}


istream& sdds::operator>>(istream& i, Contact& contact)
{
	contact.read(i);
	return i;
}

ostream& sdds::operator<<(ostream& o, const Contact& contact)
{
	contact.write(o);
	return o;
}

ostream& sdds::printPostalCode(ostream& o, const char* postalCode)
{
	char first[4]{};
	char second[4]{};
	for (int i = 0; i < 3; i++)
	{
		first[i] = postalCode[i];
		second[i] = postalCode[i + 3];
	}
	o << first << " " << second;
	return o;
	
}
