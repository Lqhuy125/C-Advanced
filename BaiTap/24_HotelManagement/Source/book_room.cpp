#include <book_room.h>

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