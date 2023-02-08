/*Joshua Dinham
121752226
BTP200 NAA
All work was done by me
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
	Department::Department()
	{
		name = nullptr;
		project = nullptr;
		numberOfProjects = 0;
		budgetDepartment = 15345.99;
	}

	void Department::updateName(const char* newName)
	{
		
		if (newName[0] == '\0' || newName == nullptr)
		{
			cout << "Give input please!" << endl;
			return;
		}
		else
		{
			delete[] this->name;
			this->name = new char[strlen(newName) + 1];
			strcpy(this->name, newName);
		}
	}
	//update budget of the department and add new change
	void Department::updateBudget(double change)
	{
		this->budgetDepartment += change;
	}
	//calculate and return the expenses  of a department
	double Department::totalexpenses()
	{
		double totalCost = 0;

		if (!(this->project == NULL))
		{
			for (int i = 0; i < this->numberOfProjects; i++)
			{
				totalCost += this->project[i].m_cost;
			}

		}
		else
		{
			return 0;
		}



		return totalCost;

	}

	//Add new project is total cost !> allocated budget
	bool Department::addProject(Project& newProject)
	{
		int size = this->fetchNumProjects();
		if (newProject.m_cost > remainingBudget())
		{
			return false;
		}
		else
		{
			if (this->fetchNumProjects() == 0)
			{
				this->project = new Project[1];
				this->project[0] = newProject;
				this->numberOfProjects++;
			}
			else
			{
				Project* tempProjects = new Project[this->numberOfProjects + 1];
				for (int i = 0; i < this->numberOfProjects; i++)
				{
					tempProjects[i] = this->project[i];
					if (i + 1 == this->numberOfProjects)
					{
						tempProjects[i + 1] = newProject;
					}
				}
				delete[] this->project;
				this->numberOfProjects += 1;

				this->project = new Project[this->fetchNumProjects()];
				for (int i = 0; i < this->fetchNumProjects(); i++)
				{
					this->project[i] = tempProjects[i];

				}
				delete[] tempProjects;
			}

			if (this->fetchNumProjects() == size)
				return false;
			else
				return true;
		}
	}

	//return numbere of projects a department is working on
	int Department::fetchNumProjects() const
	{
		return this->numberOfProjects;
	}

	//return list of projects department is working on
	Project* Department::fetchProjects() const
	{
		return this->project;
	}

	char* Department::fetchName() const
	{
		return this->name;
	}

	double Department::fetchBudget() const
	{
		return this->budgetDepartment;
	}

	//calculate and return remaining budget of a department
	double Department::remainingBudget()
	{
		return this->budgetDepartment - totalexpenses();
	}

	//use UpdateName, addProjet and updateBudget to set name of department, add a project to it and update  budget
	void Department::createDepartment(const char* newName, Project& newProject, double change)
	{
	
			this->updateName(newName);
			this->addProject(newProject);
			this->updateBudget(change);
		
	}

	//clear all dynamic memory of a department
	void Department::clearDepartment()
	{
		delete[] this->name;
		delete[] this->project;
	}

	//fully provided for students to display details of a project
	void display(const Project& project) {
		cout << "Project " << project.m_topic
			<< " will cost a total of " << project.m_cost << " C$." << endl << endl;
	}

	//fully provided for students to display details of a department
	void display(const Department& department) {
		Project* temp = department.fetchProjects();
		int projects = department.fetchNumProjects();
		cout << "Department " << department.fetchName() << " details:" << endl << endl;
		cout << "Budget: " << department.fetchBudget()
			<< " and the number of projects in progress is: " << projects << endl << endl;
		cout << "Below are the details of the projects we are currently working on: " << endl << endl;
		for (int i = 0; i < projects; i++) {
			display(temp[i]);
		}
	}

}