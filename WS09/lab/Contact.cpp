#include "Contact.h"
using namespace sdds;
using std::cout;
Contact& sdds::Contact::operator=(const Contact& contact)
{
	if (*this != contact)
	{
		Person::operator=(contact);
		delAlloCopy(m_address, contact.m_address);
		delAlloCopy(m_city, contact.m_address);
		strCpy(m_province, contact.m_province);
		strCpy(m_postalCode, contact.m_province);
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
	cout << "read(istream&) not implemented yet\n";
	return i;
}

ostream& sdds::Contact::write(ostream& o) const
{
	cout << "Contact::write(ostream&) not implemented yet\n";
	return  o;
}

sdds::Contact::operator bool() const
{
	return Person::operator bool() && m_address && m_address[0] && m_city && m_city[0] && m_postalCode[0] && strLen(m_postalCode) == 6 && m_province[0] && strLen(m_province) == 2;
}

void sdds::Contact::operator~()
{
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
