#include <customer_management.h>

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