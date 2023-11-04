#include <Function.h>

void func_login(BankingApp *acc){
    bool check_login = false;

    while (!check_login)
    {
        string username, password;
        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;
        check_login = acc->login(username, password);
        if(!check_login) cout << "Failded login. Enter again!" << endl;
        else{
            cout << "Login Success!" << endl;
            check_login=true;
        } 
    }
}

void notificationThread(BankingApp& userAccount, bool& exitFlag) {
    while (!exitFlag) {
        std::this_thread::sleep_for(std::chrono::seconds(10)); 
        std::cout << "\nThong bao tu ngan hang: Phien lam viec da het han!" << std::endl;
    }
}