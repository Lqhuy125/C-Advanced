#include <function.h>

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

void Employee_Management(vector<Employee>& databaseEmployee){
    int i;
    string out_prog;
    while(1){
        int key;
        cout << "----------------Quan li nhan vien---------------------\n\n";
        cout << "1:Chinh sua nhan vien\n";
        cout << "2:Xoa nhan vien\n";
        cout << "3:Them nhan vien\n";
        cout << "4:In danh sach nhan vien\n";
        cout << "0:Quay lai\n";

        cin >> key;
        switch (key)
        {
        case 1:
            Update_Employee(databaseEmployee);
            return;
            break;
        case 2:
            Delete_Employee(databaseEmployee);
            return;
            break;
        case 3:
            Add_Employee(databaseEmployee);
            return;
            break;
        case 4:
            Print_List_of_Employee(databaseEmployee);
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
string Translate_Position(JobPosition job){
    switch (job)
    {
    case JANITOR:
        /* code */
        return "JANITOR";
        break;
    case RECEPTIONIST:
        /* code */
        return "RECEPTIONIST";
        break;
    case LAUNDRY_STAFF:
        /* code */
        return "LAUNDRY_STAFF";
        break;
    case LAUNGGAGE_STAFF:
        /* code */
        return "LAUNGGAGE_STAFF";
        break;
    case GRADENER:
        /* code */
        return "GRADENER";
        break;
    default:
        break;
    }
    return "";
}
void Update_Employee(vector<Employee>& databaseEmployee){
    int i, id, key, key1;
    bool flag = 0;
    string temp;
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << "ID" << "\t"; 
    cout << "Ho va ten" << "\t";
    cout << "So dien thoai" << "\t";
    cout << "Vi tri" << "\t\t";
    cout << "Thoi gian bat dau" << "\t\t";
    cout << "Thoi gian ket thuc" << "\t\t";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << databaseEmployee[i].get_ID()<< "\t";
        cout << databaseEmployee[i].get_Name()<< "\t\t";
        cout << databaseEmployee[i].get_PhoneNumber()<< "\t\t";
        cout << Translate_Position(databaseEmployee[i].get_Position())<< "\t\t";
        cout << databaseEmployee[i].get_Schedule().StartTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().StartTime.time.Minute << ":" << databaseEmployee[i].get_Schedule().StartTime.time.Second << "\t\t\t";
        cout << databaseEmployee[i].get_Schedule().EndTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Minute << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Second << "\t";
        cout << endl;
    }
    cout << endl;

    cout << "Nhap ID nhan vien can chinh sua: ";
    cin >> id;
    for (i = 0; i < databaseEmployee.size(); i++){
        if (databaseEmployee[i].get_ID() == id) break;
    }
    if (i == databaseEmployee.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua vi tri\n4:Thoi gian bat dau\n5:Thoi gian ket thuc\n0: Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {cout << "Nhap ten: ";
            string new_name; cin >>  new_name;
            databaseEmployee[i].set_Name(new_name);
            flag = 1;}
            break;
        case 2:{
            cout << "Nhap sdt: ";
            string new_phone_number; cin >>  new_phone_number;
            databaseEmployee[i].set_PhoneNumber(new_phone_number);
            flag = 1;} break;
        case 3:{
            cout << "Chon vi tri:\n";
            cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
            int temp1;
            JobPosition position;
            cin >> temp1;
            switch (temp1)
            {
            case 1:
                position = JANITOR;
                break;
            case 2:
                position = RECEPTIONIST;
                break;
            case 3:
                position = LAUNDRY_STAFF;
                break;
            case 4:
                position = LAUNGGAGE_STAFF;
                break;
            case 5:
                position = GRADENER;
                break;
            default:
                break;
            }
            databaseEmployee[i].set_Position(position);
            flag = 1;
        } break;
        case 4:{
            Type_Time timeStart;
            cout << "Nhap gio: ";
            cin >> timeStart.Hour;
            cout << "Nhap phut: ";
            cin >> timeStart.Minute;
            timeStart.Second = 0;
            Schedule newSchedule;
            newSchedule.StartTime = {timeStart, Type_Date{}};
            databaseEmployee[i].set_Schedule(newSchedule);
            flag = 1;
        } break;
        case 5:{
            Type_Time timeEnd;
            cout << "Nhap gio: ";
            cin >> timeEnd.Hour;
            cout << "Nhap phut: ";
            cin >> timeEnd.Minute;
            timeEnd.Second = 0;
            Schedule newSchedule;
            newSchedule.EndTime = {timeEnd, Type_Date{}};
            databaseEmployee[i].set_Schedule(newSchedule);
            flag = 1;
        } break;
        case 0:{
            Employee_Management(databaseEmployee);
            return;
        } break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "1: Tiep tuc\n0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 1){
                Employee_Management(databaseEmployee);
                return;
            }else{
                return;
            }
        }
    }
}
void Delete_Employee(vector<Employee>& databaseEmployee){
    int id, i;
    int size = 20;
    int key;
    
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(size) << left << "ID";
    cout << setw(size) << left << "Ho va ten";
    cout << setw(size) << left << "So dien thoai";
    cout << setw(size) << left << "Vi tri";
    cout << setw(size) << left << "Thoi gian bat dau";
    cout << setw(size) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(size) << left << databaseEmployee[i].get_ID();
        cout << setw(size) << left << databaseEmployee[i].get_Name();
        cout << setw(size) << left << databaseEmployee[i].get_PhoneNumber();
        cout << setw(size) << left << Translate_Position(databaseEmployee[i].get_Position());
        cout << databaseEmployee[i].get_Schedule().StartTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().StartTime.time.Minute << ":" << setw(size) << left << databaseEmployee[i].get_Schedule().StartTime.time.Second;
        cout << databaseEmployee[i].get_Schedule().EndTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Minute  << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Second;
        cout << endl;
    }
    cout << endl;

    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
    for (i = 0; i < databaseEmployee.size(); i++){
        if (databaseEmployee[i].get_ID() == id) break;
    }
    if (i == databaseEmployee.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }

    while (1){
        system("cls");
        cout << "Ban co chac chan khong?\n";
        cout << "\n";
        cout << "1: Co\n          2: Khong\n";
        cout << "\n";
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            databaseEmployee.erase(databaseEmployee.begin() + i);
            system("cls");
            cout << "Xoa thanh cong\n";
            while (1){
                cout << "\n";
                cout << "1: Tiep tuc xoa\n";
                cout << "0: Quay lai\n\n";
                cout << "\n";
                cout << "Nhap lua chon: ";
                cin >> key;
                switch (key)
                {
                case 1:
                    Delete_Employee(databaseEmployee);
                    return;
                    break;
                case 0:
                    return;
                    break;
                default:
                    cout << "Phim nay khong hop le\n";
                    break;
                }
            }
            return;
            break;
        case 2:
            Delete_Employee(databaseEmployee);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}
void Add_Employee(vector<Employee>& databaseEmployee){
    cout << "----------------Them nhan vien---------------------\n";
    cout << "Nhap ten: ";
    string name; cin >> name;
    cout << "Nhap sdt: ";
    string sdt; cin >> sdt;
    cout << "Chon vi tri:\n";
    cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
    int temp;
    JobPosition position;
    cin >> temp;
    switch (temp)
    {
    case 1:
        position = JANITOR;
        break;
    case 2:
        position = RECEPTIONIST;
        break;
    case 3:
        position = LAUNDRY_STAFF;
        break;
    case 4:
        position = LAUNGGAGE_STAFF;
        break;
    case 5:
        position = GRADENER;
        break;
    default:
        break;
    }
    Type_Time timeStart;
    cout << "Gio bat dau: ";
    cin >> timeStart.Hour;
    cout << "Phut bat dau: ";
    cin >> timeStart.Minute;
    timeStart.Second = 0;

    Type_Time timeEnd;
    cout << "Gio ket thuc: ";
    cin >> timeEnd.Hour;
    cout << "Phut ket thuc: ";
    cin >> timeEnd.Minute;
    timeEnd.Second = 0;

    Schedule schedule;
    schedule.StartTime = {timeStart, Type_Date{}};
    schedule.EndTime = {timeEnd, Type_Date{}};
    Employee tempEmployee = {name, sdt, position, schedule};
    databaseEmployee.push_back(tempEmployee);

    cout << "Them thanh cong!!!\n";
    cout << "Nhap phim bat ky de quay lai: ";
    string temp4;
    cin >> temp4;
    return;
}
void Print_List_of_Employee(vector<Employee>& databaseEmployee){
    int i;
    int size = 20;
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(size) << left << "ID";
    cout << setw(size) << left << "Ho va ten";
    cout << setw(size) << left << "So dien thoai";
    cout << setw(size) << left << "Vi tri";
    cout << setw(size) << left << "Thoi gian bat dau";
    cout << setw(size) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(size) << left << databaseEmployee[i].get_ID();
        cout << setw(size) << left << databaseEmployee[i].get_Name();
        cout << setw(size) << left << databaseEmployee[i].get_PhoneNumber();
        cout << setw(size) << left << Translate_Position(databaseEmployee[i].get_Position());
        cout << databaseEmployee[i].get_Schedule().StartTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().StartTime.time.Minute << ":" << setw(size) << left << databaseEmployee[i].get_Schedule().StartTime.time.Second;
        cout << databaseEmployee[i].get_Schedule().EndTime.time.Hour << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Minute  << ":" << databaseEmployee[i].get_Schedule().EndTime.time.Second;
        cout << endl;
    }
    cout << endl;
    cout << "Nhap phim bat ky de quay lai: ";
    string temp;
    cin >> temp;
    return;
}