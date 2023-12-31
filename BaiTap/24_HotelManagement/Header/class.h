#ifndef __class
#define __class
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef struct {
    int Day;
    int Month;
    int Year;
} Type_Date;

typedef struct{
    int Second;
    int Minute;
    int Hour;
} Type_Time;

typedef enum{
    IN,
    OUT
}Status;

// CUSTOMER
typedef struct {
    Type_Date date;
    Type_Time time;
    Status status;
}bookHistory;
//================================================================CLASS=================================================================
class Customer{
    private:
        int idRoom;
        string NAME;
        string PHONE_NUMBER;
        string ADDRESS;
        vector<bookHistory>History;
    public:
        Customer(int id, string cusName, string cusPhone, string cusAddress);
        vector<bookHistory> &getBookingHistorys();
        void setName(string cusName);
        void setPhoneNumber(string cusPhone);
        void setAddress(string cusAddress);
        string getName();
        string getPhoneNumber();
        string getAddress();
        int get_ID_Room();
};
class CustomerManagement{
    public:
        vector<Customer> databaseCustomer;

        vector<Customer> &getDatabaseCustomer(){ return databaseCustomer;};
};

class Room{
    private:
        int ROOM_NUMBER;
        bool IS_BOOKED;
        bool IS_CLEANED;
    public:
        Room(int room_number);
        int getRoomNumber();
        bool Get_Reserved_Room();
        //Check xem phong do co san de thue hay khong
        bool isAvailable();
        void bookRoom();
        void checkOut();
};

typedef enum{
    JANITOR, //nguoi gac cong
    RECEPTIONIST, //Nhan vien le tan
    LAUNDRY_STAFF, //Nhan vien giat ui
    LAUNGGAGE_STAFF, // ?
    GRADENER //Nguoi lam vuon
} JobPosition;

// EMPLOYEE
typedef struct{
    Type_Time time;
    Type_Date date;
} worktime;

typedef struct{
    worktime StartTime;
    worktime EndTime;
} Schedule;

class Employee{
    private:
        int ID;
        string NAME;    
        string PHONE_NUMBER;
        JobPosition POSITION;
        Schedule SCHEDULE;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule schedule){
            static int id = 100;
            ID = id; id++;
            NAME = nameEmployee;
            PHONE_NUMBER = phoneNumberEmployee;
            POSITION = positionEmployee;
            SCHEDULE = schedule;
        };
        string get_Name();
        string get_PhoneNumber();
        int get_ID();
        JobPosition get_Position();
        Schedule get_Schedule();

        void set_Name(string name);
        void set_PhoneNumber(string phonenumber);
        void set_Position(JobPosition position);
        void set_Schedule(Schedule schedule);
};  
class EmployeeManagement{
    public:
        vector<Employee> databaseEmployee;

        vector<Employee> &get_databaseEmployee(){ return databaseEmployee; };
        void update_employee();
};

class User{
    private:
        int ID;
        string USENAME;
        string PASSWORD;
    public:
        User(string username = " ", string password = " ");
        void set_Usename(string name);
        void set_Password(string pass);
        void set_ID(int id);

        int get_ID();
        string get_Usename();
        string get_Password();

        bool authenticate(string inputUsename, string inputPassword);
};

// Manage security.
class SecureManagement{
    private:
        User user_Admin;
        vector<User> data_User;      
    public:
        SecureManagement(){
            user_Admin.set_Username("admin");
            user_Admin.set_Password("admin");
        }
        void add_User(int id_user, string input_username, string input_password);
        void remove_User(int id_user);
        void change_Password_User(string input_username, string new_password);
        void edit_Pass_Addmin(string new_pass);
        bool get_Check_Signup_Admin(string input_username, string input_password);
        vector<User> & get_database_User();
};
// class UserManagement{
//     private:
//         User user;
//         vector<User> databaseUser;
//         bool checkSignUp;
//     public:
//         UserManagement(){
//             user.set_Usename = "manager";
//             user.set_Password = "admin";
//         } 
//         void set_PassWordManagement(string pass);
//         void add_User(int employeeID, string username, string password, JobPosition position);
//         void erase_User();
//         void edit_User();
// }
// void UserManagement::set_PassWordManagement(string pass){
//     user.set_Password(pass);
// }

class Feedback_info{
    private:
        string name_customer;
        string feedback;
        double rate;
    public:
        Feedback_info(string name, string review, double mark){
            name_customer = name;
            feedback = review;
            rate = mark;
        } 
};
#endif