#include <function.h>


int main(int argc, char const *argv[])
{
    vector<Room> DATABASE_ROOM;
    CustomerManagement CustomerManagement;
    vector<Employee> databaseEmployee;
    
    int option=0;
    while(1){
        cout << "----------------WELCOME---------------------\n";
        cout << "1:Dat phong\n";
        cout << "2:Quan li khach hang\n";
        cout << "3:Quan li nhan vien\n";
        cout << "4.Thanh toan\n";
        cout << "5:Bao mat va quyen truy cap\n";
        cout << "6:Bao cao va thong ke\n";
        cout << "7:Quan li va phan hoi danh gia\n";
        cout << "0:Thoat\n";
        cout << "Nhap lua chon: ";
        cin>>option;

        switch(option){
            case 1:
                bookRoom(DATABASE_ROOM, CustomerManagement);
                break;
            case 2:
                cusManager(DATABASE_ROOM, CustomerManagement);
                break;
            case 3:
                Employee_Management(databaseEmployee);
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 0:
                cout << "======Good bye======";
                return 0;
                break;
        }
    }
}

