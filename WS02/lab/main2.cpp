#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define filename_r "test.txt"

FILE* fp;
struct Customers {
    int user_id;
    
};

Customers* users = nullptr; 
int numOfCustomers = 0;

int openFile_r(const char filename[]); // Provided
void closefile(); // Provided

void closefile() { // Fully provided
    if (fp) fclose(fp);
}
int noOfTraces(); // Provided

int openFile_r(const char filename[]) { // Fully provided
    fp = fopen(filename_r, "r");
    return fp != NULL;
}
int noOfTraces() {  // Fully provided
    int noOfTraces = 0;
    char ch;
    while (fscanf(fp, "%c", &ch) == 1) {
        noOfTraces += (ch == '\n');
    }
    rewind(fp);
    return noOfTraces;
}
// ADD: Declare read prototypes (4 prototypes)


int read(char* packageName);

int read(int num);

//int read(double timeInHours);
//
//int read(char dayOfWeek);


int read(char* packageName)
{
    return fscanf(fp, "%60[^\n]\n", packageName) == 1;
}

int read(int num)
{
    return fscanf(fp, "%d,", &num) == 1;
}

//int read(double timeInHours)
//{
//    return fscanf(fp, "%lf,", &timeInHours) == 1;
//
//}
//
//int read(char dayOfWeek)
//{
//    return fscanf(fp, "%c", &dayOfWeek) == 1;
//
//}

void initializeCustomerList();
void initializeCustomerList()
{
    bool check = true;
    int i = 0;
    users = new Customers[numOfCustomers];

    if (openFile_r(filename_r)) {
        numOfCustomers = noOfTraces();


        for (i = 0; i < numOfCustomers && check; i++)
        {
            check =read(users[i].user_id);
        }
    }

}
void printCustomerList();
void printCustomerList()
{
    for (int i = 0; i < numOfCustomers; i++)
    {
        cout << users[i].user_id << " "
           << endl;
    }
}

//void strCpy(char* des, const char* src); // Provided
//int strLen(const char* s); // Provided
int main()
{
    initializeCustomerList();
    printCustomerList();
}