#pragma once
#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

	const int MAX_TOPIC_LENGTH = 25;

	struct Project {
		char m_topic[MAX_TOPIC_LENGTH + 1];
		double m_cost;
	};

	//class Department does here
	class Department {
		char* name;
		Project* project;
		int numberOfProjects;
		double budgetDepartment;

	public:
		//Constructor
		Department();

		//sets name of the department
		void updateName(const char* newName);

		//update budget of the department and add new change
		void updateBudget(double change);

		//calculate and return the expenses  of a department
		double totalexpenses();

		//Add new project is total cost !> allocated budget
		bool addProject(Project& newProject);

		//return number of projects a department is working on
		int fetchNumProjects() const;

		//return name of the department
		char* fetchName() const;

		//return the current budget of the department
		double fetchBudget() const;

		//return list of projects department is working on
		Project* fetchProjects() const;

		//calculate and return remaining budget of a department
		double reminaingBudget();

		//use UpdateName, addProjet and updateBudget to set name of department, add a project to it and update  budget
		void createDepartment(const char* newName, Project& newProject, double change);

		//clear all dynamic memory of a department
		void clearDepartment();

		void display();
	};

	

} 
#endif //!SDDS_DEPARTMENT_H