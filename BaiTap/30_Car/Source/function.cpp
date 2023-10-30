#include <function.h>

void add(vector<Car*>& data){
    int addChoice = 0;
    cout << "Them xe:" << endl;
    cout << "1. Them Motor" << endl;
    cout << "2. Them Oto" << endl;
    cout << "Chon loai xe muon them: ";
    cin >> addChoice;

    if (addChoice == 1) {
        string hangxe, mauxe, loaixe;
        int sobanh;

        cout << "Nhap thon tin Motor:" << endl;
        cout << "Hang xe: "; cin >> hangxe;
        cout << "Mau xe: "; cin >> mauxe;
        cout << "So banh: "; cin >> sobanh;
        cout << "Loai xe: "; cin >> loaixe;

        Motor* motor = new Motor(hangxe, mauxe, sobanh, loaixe);
        data.push_back(motor);
    } else if (addChoice == 2) {
        string hangxe, mauxe, kieudongco;
        int sobanh, soghe;

        cout << "Nhap thong tin Oto:" << endl;
        cout << "Hang xe: "; cin >> hangxe;
        cout << "Mau xe: "; cin >> mauxe;
        
        cout << "So ghe: "; cin >> soghe;
        cout << "Kieu đong co: "; cin >> kieudongco;

        Oto* oto = new Oto(hangxe, mauxe, 2, soghe, kieudongco);
        data.push_back(oto);
    } else
        cout << "Lua chon khong hop le." << endl;
}
void display(vector<Car*>& data){
    int choiceDisplay = 0;

    cout << "Display" << endl;
    cout << "1. Hien thi xe Motor" << endl;
    cout << "2. Hien thi xe Oto" << endl;
    cout << "3. Hien thi danh sach database" << endl;
    cin >> choiceDisplay;

    if(choiceDisplay == 1){
        cout << "========Danh sach xe Motor trong DB========\n";
        for (auto item : data) {
            if (item->getType() == "Motor") {
                item->hienThi();
            }
        }
    }
    else if (choiceDisplay == 2){
        cout << "========Danh sach xe Oto trong DB========\n";
    
    }
    else if (choiceDisplay == 3){
        cout << "========Danh sach xe trong DB========\n";
        for( auto item : data){
            item->hienThi();
        }
    }
    else 
        cout << "Lua chon khong hop le." << endl;
}