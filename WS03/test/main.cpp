#include <iostream>
#include <string>
#include "Department.h"
using namespace std;
using namespace sdds;

int main() {
	Project testProject = { "Base",551.55 };

	Project myprojects[5] = { {"Synergy", 5041.55},
							  {"Mecha", 2925.99},
							  {"Chroma", 3995.45},
							  {"Force", 6988.45},
							  {"Oculus", 7441.22}
	};

	Department SDDS{};

	//Test2
	cout << endl << "**********Update Name TEST Start**********" << endl;
	SDDS.updateName("Software Development and design");
	//SDDS.display();
	SDDS.updateBudget(500000000.505);
	//SDDS.display();

	SDDS.addProject(testProject);
	SDDS.display();
	for (int i = 0; i < sizeof(myprojects) / sizeof(myprojects[0]); i++)
	{
		SDDS.addProject(myprojects[i]);
		SDDS.display();
		
	}

	cout << "**********Update Name TEST END**********" << endl;
}