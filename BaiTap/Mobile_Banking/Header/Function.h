#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <iostream>
#include <MobileBanking.h>

using namespace std;
void func_login(BankingApp *acc);
void notificationThread(BankingApp& userAccount, bool& exitFlag);

#endif