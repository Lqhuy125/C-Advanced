#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int Day;
    int Month;
    int Year;
}Date;

typedef struct {
    int second;
    int minute;
    int hour;
}Time;

typedef enum{
    IN,
    OUT
}Status;

typedef struct {
    Date date;
    Time time;
    Status status;
}bookHistory;
//==========================================CLASS==========================================
class Customer{
    private:
        int idRoom;
        string NAME;
        string PHONE_NUMBER;
        string ADDRESS;
        vector<bookHistory>History;
    public:
        Customer(int id, string cusName, string cusPhone, string cusAddress){
            NAME = cusName;
            PHONE_NUMBER = cusPhone;
            ADDRESS = cusAddress;
            idRoom = id;
        };
        vector<bookHistory> &getBookingHistorys(){ return History;};
        void setName(string cusName){
            NAME = cusName;
        };
        void setPhoneNumber(string cusPhone){
            PHONE_NUMBER = cusPhone;
        };
        void setAddress(string cusAddress){
            ADDRESS = cusAddress;
        };
        string getName(){
            return NAME;
        };
        string getPhoneNumber(){
            return PHONE_NUMBER;
        };
        string getAddress(){
            return ADDRESS;
        };
        int get_ID_Room(){
            return idRoom;
        }
};
class CustomerManagement {
    public:
        vector<Customer> databaseCustomer;

    public:
        vector<Customer> &getDatabaseCustomer(){ return databaseCustomer;};
        void addCustomer(Customer customer);
        void updateCustomer();
        void removeCustomer();
        void displayCustomerInfor();
        void CustomerMenu();
};
void CustomerManagement::addCustomer(Customer customer){
    databaseCustomer.push_back(customer);
}
class Room{
    private:
        int ROOM_NUMBER;
        bool IS_BOOKED;
        bool IS_CLEANED;
    public:
        Room(int room_number){
            ROOM_NUMBER = room_number;
            IS_BOOKED = false;
            IS_CLEANED = true;
        };
        int getRoomNumber(){ 
            return ROOM_NUMBER; 
        };
        bool Get_Reserved_Room(){
            return this->IS_BOOKED;
        }; 
        //Check xem phong do co san de thue hay khong
        bool isAvailable(){
            return !IS_BOOKED && IS_CLEANED;
        };
        void bookRoom(){
            IS_BOOKED = true;
            IS_CLEANED = false;
        };
        void checkOut(){
            IS_BOOKED = false;
        };
        
};
//========================================FUNCTION==========================================
void TienHanhDatPhong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void Nhapsophong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void Updatetrangthaidondep(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void bookRoom(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement);
void Edit_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);
void Delete_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);
void cusManager(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement);

void Nhapsophong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement){
    cout << "Nhap so phong: ";
    int numberRoomTemp;
    cin >> numberRoomTemp;
    {
        Room roomTemp = {numberRoomTemp};
        databaseRoom.push_back(roomTemp);
    }
    cout << "Thiet lap so phong thanh cong!!!\n";
    while (1){
        cout << "Nhan so bat ky de quay lai: ";
        int key1;
        cin >> key1;
        break;
    }
}
void Updatetrangthaidondep(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement){

}
void TienHanhDatPhong(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement){
    int i;
    string out_prog;
    //Danh sach cac phong va trang thai
    cout << "----------------Tien hanh dat phong---------------------\n\n";
    if (databaseRoom.size() == 0){
        cout << "Hien tai khong co phong\n";
        while (1){
            cout << "Nhan so bat ky de quay lai: ";
            int key1;
            cin >> key1;
            break;
        }
    }
    else{
        cout<<"So phong"<<"\t"<<"Trang thai\n";
        for (int i = 0; i < databaseRoom.size(); i++){
            cout << databaseRoom[i].getRoomNumber()<<"\t\t";
            cout << databaseRoom[i].Get_Reserved_Room();
            cout << endl;
        }
        cout << "1:Nhap so phong\n";
        cout << "0:Quay lai\n";
        
        while(1){
            int key3;
            cout << "Nhap lua chon: ";
            cin >> key3;
            switch(key3){
                case 1:{
                    cout << "Nhap so phong: ";
                    int numberRoomTemp;
                    cin >> numberRoomTemp;
                    for (i = 0; i , databaseRoom.size(); i++){
                        if (numberRoomTemp == databaseRoom[i].getRoomNumber()) break;
                    }        
                    if (databaseRoom[i].Get_Reserved_Room()){
                        //system("cls");
                        cout << "Phong nay da duoc dat!!!\n";
                        cout << "Nhan phim bat ky de quay lai: ";
                        cin >> out_prog;
                        return;
                    }
                    cout << "----------------Tien hanh dat phong---------------------\n\n";
                    cout << "Nhap ten: ";
                    string name; cin >> name;
                    cout << "Nhap sdt: ";
                    string sdt; cin >> sdt;
                    cout << "Nhap dia chi: ";
                    string address; cin >> address;

                    Customer customerTemp(numberRoomTemp, name, sdt, address);
                    CustomerManagement.databaseCustomer.push_back(customerTemp);
                    databaseRoom[i].bookRoom(); //Sau khi them phong, Set phòng đó đã được đặt

                    cout << "----------------Dat phong thanh cong---------------------\n\n";
                    cout << "1:Tiep tuc dat phong\n";
                    cout << "0:Quay lai\n\n";

                    while (1)
                    {
                        cout << "Nhap lua chon: ";
                        int key4;
                        cin >> key4;
                        switch (key4)
                        {
                        case 1:
                            bookRoom(databaseRoom, CustomerManagement);
                            return;
                            break;
                        case 0:
                            return;
                            break;
                        }
                    }
                } break;
                case 0:{
                    return;
                }break;
            }
        }
    }
}
void bookRoom(vector<Room> &databaseRoom, CustomerManagement &CustomerManagement){
    while(1){
        cout << "----------------Dat phong---------------------\n\n";
        cout << "1:Thiet lap so phong\n";
        cout << "2:Update trang thai don dep\n";
        cout << "3:Tien hanh dat phong\n";
        cout << "0:Quay lai\n\n";
        cout << "Nhap lua chon: ";
        int key; cin >> key;

        switch(key){
            case 1:
                Nhapsophong(databaseRoom, CustomerManagement);
                break;
            case 2:
                Updatetrangthaidondep(databaseRoom, CustomerManagement);
                break;
            case 3:
                TienHanhDatPhong(databaseRoom, CustomerManagement);
                break;
            case 0:
                return;
                break;
        }
    }
}

void cusManager(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement){
    int i;
    int key;
    cout << "----------------Quan li khach hang---------------------\n\n";
    cout << "STT\t";
    cout << "ID Phong\t";
    cout << "Ho va ten\t";
    cout << "So dien thoai\t";
    cout << "Dia chi\n";
    for (i = 0; i < CustomerManagement.databaseCustomer.size(); i++){
        cout << i + 1<<"\t";
        cout << CustomerManagement.databaseCustomer[i].get_ID_Room()<<"\t\t";
        cout << CustomerManagement.databaseCustomer[i].getName()<<"\t\t";
        cout << CustomerManagement.databaseCustomer[i].getPhoneNumber()<<"\t\t";
        cout << CustomerManagement.databaseCustomer[i].getAddress();
        cout << endl;
    }
    cout << "1:Chinh sua thong tin\n";
    cout << "2:Xoa thong tin\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            Edit_Infor_Customer(databaseRoom, CustomerManagement);
            return;
            break;
        case 2:
            Delete_Infor_Customer(databaseRoom, CustomerManagement);
            return;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}
void Edit_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement){
    int stt;
    bool continueEdit = 1;
    int key, key1;
    bool flag = 0;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    string new_name, new_phone, new_add;
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua dia chi\n0: Quay lai\n";
    while (continueEdit){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "Nhap ten: "; cin >> new_name;
            CustomerManagement.databaseCustomer[stt-1].setName(new_name);
            flag = 1;
            break;
        case 2:
            cout << "Nhap sdt: "; cin >> new_phone;
            CustomerManagement.databaseCustomer[stt-1].setPhoneNumber(new_phone);
            flag = 1;
            break;
        case 3:
            cout << "Nhap dia chi: "; cin >> new_add;
            CustomerManagement.databaseCustomer[stt-1].setAddress(new_add);
            flag = 1;
            break;
        case 0:
            cusManager(databaseRoom, CustomerManagement);
            return;
            break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "1: Tiep tuc\n0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 1){
                Edit_Infor_Customer(databaseRoom, CustomerManagement);
                return;
            }else{
                cusManager(databaseRoom, CustomerManagement);
                return;
            }
        }
    }
}
void Delete_Infor_Customer(vector<Room>& databaseRoom, CustomerManagement &CustomerManagement){
    int stt;
    int key, key1;
    int i;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    cout << "1:Chan chan xoa\n0:Quay lai\n";
    while(1){
        cout << "Nhap lua chon: \n";
        cin >> key;
        switch(key){
            case 1:{
                for( i = 0; i < CustomerManagement.databaseCustomer.size(); i++){
                    if(CustomerManagement.databaseCustomer[i].get_ID_Room() == databaseRoom[i].getRoomNumber())
                        break;
                }
                databaseRoom[i].checkOut();
                CustomerManagement.databaseCustomer.erase(CustomerManagement.databaseCustomer.begin() + stt - 1);
                cout << "Xoa thong tin thanh cong!!!\n";
                cout << "Nhan phim bat ki de quay lai\n";
                cin >> key1;
                return;
            } break;

            case 0: {
                Delete_Infor_Customer(databaseRoom, CustomerManagement);
                return;
            } break;
        }
    }

}
int main(int argc, char const *argv[])
{
    vector<Room> DATABASE_ROOM;
    CustomerManagement CustomerManagement;
    
    //kHOI TAO ROOM START
    Room roomTemp = {10};
    DATABASE_ROOM.push_back(roomTemp);
    Room roomTemp1 = {11};
    DATABASE_ROOM.push_back(roomTemp1);
    Room roomTemp2 = {12};
    DATABASE_ROOM.push_back(roomTemp2);

    //kHOI TAO CUSTOMER START
    Customer customerTemp(10, "Huy", "012412", "VP");
    CustomerManagement.databaseCustomer.push_back(customerTemp);
    DATABASE_ROOM[0].bookRoom();
    Customer customerTemp1(11, "Nam", "017241", "HN");
    CustomerManagement.databaseCustomer.push_back(customerTemp1);
    DATABASE_ROOM[1].bookRoom();

    int option=0;
    while(1){
        cout << "----------------WELCOME---------------------\n";
        cout << "1:Dat phong\n";
        cout << "2:Quan li khach hang\n"
        cout << "3:Quan li nhan vien\n";
        cout << "4.Thanh toan\n5:Bao mat va quyen truy cap\n6:Bao cao va thong ke\n";
        cout << "7:Quan li va phan hoi danh gia\n0:Thoat\n\n";
        cout << "Nhap lua chon: ";
        cin>>option;

        switch(option){
            case 1:
                bookRoom(DATABASE_ROOM, CustomerManagement);
                break;
            case 2:
                cusManager(DATABASE_ROOM, CustomerManagement);
                break;
            case 0:
                cout << "======Good bye======";
                return 0;
                break;
        }
    }
}
