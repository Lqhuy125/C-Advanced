#include <iostream>
#include <thread>

#include <MobileBanking.h>
#include <Function.h>

int main(int argc, char const *argv[])
{
    BankingApp account("admin", "admin", 1000);
    bool exitFlag = false;
    thread notifyThread(notificationThread, ref(account), ref(exitFlag));

    func_login(&account);

    int option=0;
    while(option!=4){
        cout << "--------OPTION--------\n";
        cout << "1. Kiem tra so du.\n";
        cout << "2. Nap tien.\n";
        cout << "3. Rut tien.\n";
        cout << "4. Thoat\n";
        cout << "Enter option: "; cin >> option;

        switch(option){
            case 1:
                cout << "So du hien tai: " << account.check_sodu() << endl;
                break;
            case 2:
                account.naptien();
                break;
            case 3:
                account.ruttien();
                break;
            case 4:
                option = 4;
                break;
            default:
                cout << "Chon sai. Vui long chon lai." << endl;
        }
    }
    
    exitFlag = true;
    notifyThread.join();
    return 0;
}
