#include <Car.h>
#include <Oto.h>
#include <Motor.h>
#include <function.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Car*> database;

    Oto oto1("Honda", "mau do", 4, 5, "Xang");
    Oto oto2("Toyota", "mau den", 4, 4, "Dau");

    Motor motor1("Wave", "mau den", 2, "Xe so");
    Motor motor2("Wave", "mau do", 2, "Xe ga");

    database.push_back(&oto1);
    database.push_back(&oto2);
    database.push_back(&motor1);
    database.push_back(&motor2);

    int choice = 0;
    
    while ( choice != 3)
    {
        cout << "MENU:" << endl;
        cout << "1. Add new car" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Thoat" << endl;
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add(database);
            break;
        case 2:
           display(database);
            break;
        case 3:
            cout << "Ket thuc chuong trinh!" << endl; 
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    }
    
}
