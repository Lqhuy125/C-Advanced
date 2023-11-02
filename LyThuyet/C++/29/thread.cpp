#include <iostream>
#include <thread> // Da luong
#include <chrono> // Tao delay

using namespace std;

void TASK1(){
    int i = 0;
    while (1)
    {
        this_thread::sleep_for(chrono::seconds(1)); // Lam cho chuong trinh delay 1s
        cout << "task1 = " << i++ << endl;
    }
}
void TASK2(){
    int i = 0;
    while (1)
    {
        this_thread::sleep_for(chrono::seconds(3)); // Lam cho chuong trinh delay 1s
        
        cout << "task2 = " << i++ << endl;
        cout << "-----------------\n";
    }
}
int main(int argc, char const *argv[])
{
    thread t1(TASK1);
    thread t2(TASK2);

    t1.join();
    t2.join();
    
    return 0;
}
