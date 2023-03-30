/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Tools.h"
#include "Person.h"
namespace sdds
{
	using std::istream; using std::ostream;
	class Contact : public Person
	{
		char* m_address{};
		char* m_city{};
		char m_province[16]{};
		char m_postalCode[16]{};
	public:
		 Contact(){};
		 Contact& operator=(const Contact&);
		 Contact(const Contact&);
		 ~Contact();
		 istream& read(istream&) override;
		 ostream& write(ostream&) const override;
		 operator bool() const override;
		 void operator~() override;
		
	};
	istream& operator>>(istream&, Contact&);
	ostream& operator<<(ostream&,const Contact&);
	ostream& printPostalCode(ostream& o, const char* postalCode);

}
#endif // !SDDS_CONTACT_H
