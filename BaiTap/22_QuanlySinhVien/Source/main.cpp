#include <student.h>

int main()
{
    SinhVien sv1 = SinhVien("Quang", 21, NAM, 9, 7, 8); 
    SinhVien sv2 = SinhVien("Cuong", 22, NAM, 6, 7, 8); 
    SinhVien sv3 = SinhVien("Lan", 19, NU, 10,9,10); 

    menu menu;
    menu.database.push_back(sv1);
    menu.database.push_back(sv2);
    menu.database.push_back(sv3);
    while(1){
        int options;
        cout<<"*******************************************************"<<endl;
        cout<<"choose options!"<<endl;
        cout<<"press 1 to add a new student"<<endl;
        cout<<"press 2 to update student's information by ID"<<endl;
        cout<<"press 3 to delete student by ID"<<endl;
        cout<<"press 4 to find student by name"<<endl;
        cout<<"press 5 to sort students by GPA"<<endl;
        cout<<"press 6 to sort students by name"<<endl;
        cout<<"press 7 to display students list"<<endl;
        cout<<"press 8 to exit"<<endl;
        cout<<"enter options: ";
        cin>>options;

        switch (options)
        {
        case 1:
            menu.addSinhVien();
            break;
        case 2:
            menu.updateInformationbyID();
            break;
        case 3:
            menu.deleteStudentbyID();
            break;
        case 4:
            menu.findStudentbyName();
            break;
        case 5:
            menu.sortStudentbyGPA();
            break;
        case 6:
            menu.sortStudentbyName();
            break;    
        case 7:
            menu.displayInformation();
            break;
        case 8:
            goto exit_while;
            break;
        default:
            break;
        }
    }
    exit_while: cout << "Exit. Oke" << endl;
    return 0;
}