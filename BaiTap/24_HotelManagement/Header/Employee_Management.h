#ifndef __Employee_Management
#define __Employee_Management

#include <class.h>

void Employee_Management(vector<Employee>& databaseEmployee);
void Update_Employee(vector<Employee>& databaseEmployee);
void Delete_Employee(vector<Employee>& databaseEmployee);
void Add_Employee(vector<Employee>& databaseEmployee);
void Print_List_of_Employee(vector<Employee>& databaseEmployee);
string Translate_Position(JobPosition job);

#endif