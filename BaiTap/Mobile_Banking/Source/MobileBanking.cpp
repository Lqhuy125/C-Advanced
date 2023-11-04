#include <MobileBanking.h>

bool BankingApp :: login(string user, string pass){
    return (USERNAME == user && PASSWORD == pass);
}

int BankingApp :: check_sodu(){
    return TAIKHOAN;
}

void BankingApp :: naptien(){
    double money = 0;
    cout << "Nhap so tien can nap: "; cin >> money;
    TAIKHOAN += money;
    cout << "Da nap " << money << " vao tai khoan.\n";
    cout << "So du hien tai: " << TAIKHOAN << endl;
}

void BankingApp :: ruttien(){
    double money = 0;
    cout << "Nhap so tien can rut: "; cin >> money;
    if( money > TAIKHOAN) {
        cout << "So du khong du." << endl;
        return;
    }
    else
        TAIKHOAN -= money; 
        cout << "Da rut " << money << " tu tai khoan.\n";
        cout << "So du hien tai: " << TAIKHOAN << endl;
}