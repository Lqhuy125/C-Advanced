#ifndef __MOBILE_BANKING_H
#define __MOBILE_BANKING_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
class BankingApp{
    private:
        string USERNAME;
        string PASSWORD;
        double TAIKHOAN;
        // Khai báo khoá
        mutex taikhoanMutex;
    public:
        BankingApp(string username, string password, double taikhoan) : 
            USERNAME(username), PASSWORD(password), TAIKHOAN(taikhoan) {};

        bool login(string user, string pass);
        int check_sodu();
        void naptien();
        void ruttien();

};
#endif