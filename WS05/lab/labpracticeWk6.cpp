#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>


//how do we prepare a file when we don't know how much information is in it?

//for reading files
//int main()
//{
	std::ifstream file;//input file stream
	file.open("flowchart.txt");
	if (file.is_open())
	{
		while (file) { 
			// loops and constantly adds to buffer then transfers to new dynamic character array;

		char buffer[16]; //creating a buffer; //chunk from the file... stores here why? 
		char* content = new char[1] {'\0'}; // we don't know how big the file is. all the content will be stored here
			//resizable array;
			//initialized to nullptr and dynamically so that it can be resized;

		int size = 0; //counts how many characters in content

		file.get(buffer, 16, '\0');//(where to put data, how much memory, stop at delimiter);
		if (file) //if file is open and in good state
		{
			char* tmp = new char[strlen(content) + strlen(buffer) + 1];
			strcpy(tmp, content);
			strcat(tmp, buffer);

			delete[] content;
			content = tmp;
			std::cout << content;

		}
		//...
		}

		file.close();
//}