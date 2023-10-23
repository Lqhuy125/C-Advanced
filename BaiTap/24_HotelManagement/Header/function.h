#include <class.h>
//bookRoom
void TienHanhDatPhong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void Nhapsophong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void Updatetrangthaidondep(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void bookRoom(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);

//Quan li khach hang
void Edit_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);
void Delete_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);
void cusManager(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);

//Quan li nhan vien
void Employee_Management(vector<Employee>& databaseEmployee);
void Update_Employee(vector<Employee>& databaseEmployee);
void Delete_Employee(vector<Employee>& databaseEmployee);
void Add_Employee(vector<Employee>& databaseEmployee);
void Print_List_of_Employee(vector<Employee>& databaseEmployee);

string Translate_Position(JobPosition job);

//