#include "Contact.h"
using namespace sdds;
using std::cout;
Contact& sdds::Contact::operator=(const Contact&)
{
	cout << "operator=() Not Implemented Yet\n";
	return *this;
}



sdds::Contact::Contact(Contact&) {}



sdds::Contact::~Contact()
{
	cout << "~Contact() not implemented yet\n";
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
	cout << "Contact::operator bool() not implemented yet\n";
	return true;
}

void sdds::Contact::operator~()
{
	cout << "Contact::operator~() not implemented yet\n" << std::endl;

}

istream& sdds::operator>>(istream& i, Contact& contact)
{
	contact.read(i);
	return i;
}

ostream& sdds::operator<<(ostream& o, Contact& contact)
{
	contact.write(o);
	return o;
}
