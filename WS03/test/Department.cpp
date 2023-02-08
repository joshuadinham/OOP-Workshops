#pragma
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
		
		if (newName[0] == '\0' || newName == NULL)
		{
			cout << "Give input please!" << endl;
			return;
		}
		else
		{
			char* tempname = new char[strlen(newName) + 1];
			strcpy(tempname, newName);
			delete[] this->fetchName();
			this->name = tempname;
		}
	}
	//update budget of the department and add new change
	void Department::updateBudget(double change)
	{
		budgetDepartment = change;
	}
	//calculate and return the expenses  of a department
	double Department::totalexpenses()
	{
		double totalCost = 0;
		for (int i = 0; i < this->numberOfProjects; i++)
		{
			totalCost = totalCost += this->project[i].m_cost;
		}
		return totalCost;
	}

	//Add new project is total cost !> allocated budget
	bool Department::addProject(Project& newProject)
	{
		int size = this->fetchNumProjects();
		
		if (totalexpenses() + newProject.m_cost > budgetDepartment)
		{
			cout << "Not enough budget for this project" << endl;
			return false;
		}
		else
		{
			if (this->fetchNumProjects() == 0)
			{
				this->project[0] = newProject;
				this->numberOfProjects++;
			}
			else
			{
				Project* tempProjects = new Project[this->fetchNumProjects() + 2];
				for (int i = 0; i < this->fetchNumProjects()+1; i++)
				{
					tempProjects[i] = this->project[i];
					if (i+1 == this->fetchNumProjects()+1)
					{
						tempProjects[i+1] = newProject;
					}
				}
				delete[] this->project;
				this->numberOfProjects = this->fetchNumProjects() + 1;

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

	//return number of projects a department is working on
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
	double Department::reminaingBudget()
	{
		return this->budgetDepartment - totalexpenses();
	}

	//use UpdateName, addProjet and updateBudget to set name of department, add a project to it and update  budget
	void Department::createDepartment(const char* newName, Project& newProject, double change)
	{
		if (newName[0] == '\0' || newName == NULL)
		{
			cout << "Give input please!" << endl;
			return;
		}
		else
		{
			this->updateName(newName);
			this->addProject(newProject);
			this->updateBudget(change);
		}
	}

	//clear all dynamic memory of a department
	void Department::clearDepartment()
	{
		delete[] this->name;
		delete[] this->project;
	}
   
	void Department::display(){
		cout << "The Department name is: " << name << endl;
		cout << "The Department's budget is: " << budgetDepartment << endl;
		cout << "The department's current project is: " << this->project->m_topic << " and the project's cost is: " << this->project->m_cost << ". The Department's total budget is " << this->budgetDepartment << " and after the cost of all projects it will be " << this->budgetDepartment - this->totalexpenses() << endl;
		cout << "A list of All Projects: " << endl;
		int i = 0;

		for (i = 0; i < this->numberOfProjects; i++)
		{
			cout << "[" << i+1 << "]: " << this->project[i].m_topic << " Cost: " << this->project[i].m_cost << endl;
		}
	}


}