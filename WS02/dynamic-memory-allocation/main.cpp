#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct SmartHome
{
	char* deviceName;
	int amount;
};

SmartHome* smartDevice;
FILE* fp;

int* growArray(int* p_values, int cur_size);
int* growArray(int* p_values, int cur_size)
{
	//create new array of int pointers - we just doubling this time;
	int* p_new_values = new int[cur_size * 2];

	//copy over old values to new values
	for (int i = 0; i < cur_size; ++i)
	{
		p_new_values[i] = p_values[i];
	}
	//delete old pointer array

	delete p_values;
	return p_new_values;
}

bool openFile(const char filename[]);
bool openFile(const char filename[])
{
	fp = fopen(filename, "r");
	return fp != NULL;
}

bool read(char name[])
{
	bool found = false;
	found = fscanf(fp, "%s", name);
	return found;
}

bool read(int* amount)
{
	bool found = false;
	found = fscanf(fp, "%d\n", amount);
	return found;
}

void closeFile()
{
	if (fp) fclose(fp);
	 
}

int numberOfIndices()
{
	int noOfTraces = 0;
	char ch;
	while (fscanf(fp, "%c", &ch) == 1) {
	    noOfTraces += (ch == '\n');
	}
	rewind(fp);
	return noOfTraces;
}

void dynamicAllo(const char filename[])
{
	if (openFile(filename))
	{
		int size = 4;
		smartDevice = new SmartHome[size];
		SmartHome* last = &smartDevice[size];
		bool flag = 1;
	
		for (SmartHome* p = smartDevice; p != last && flag; p++)
		{
			p->deviceName = (char*)malloc(sizeof(char) * 25);
			flag = read(p->deviceName);
		}
	
		for (SmartHome* p = smartDevice; p != last; p++)
		{
			cout<< "Device name: " << p->deviceName << endl;
		}
     
	}
	closeFile();
}

int main()
{

	const char filename[] = "test.txt";
	dynamicAllo(filename);
	
	return 0;
}