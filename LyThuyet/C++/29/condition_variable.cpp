#include <iostream>
#include <thread> // Da luong
#include <chrono> // Tao delay
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

mutex mtx;
condition_variable cond_var;
bool check = false;
vector<int> products;
void producer(){
    for(int i=0; i<10; i++){
        lock_guard<mutex> lock(mtx); //Khoá luồng này lại 
        products.push_back(i);
    }
    for (int item : products)
    {
        cout << "item: " << item << endl;
    }

    check = true;
    this_thread::sleep_for(chrono::seconds(2)); //delay 500ms
    cond_var.notify_one();
    
}

void consumer(){

    unique_lock<mutex> lock(mtx);
    cond_var.wait(lock, []{ return check; });

    for(int item : products){
        cout << "Consumer: " << item << endl;
    }
}

int main(int argc, char const *argv[])
{
    thread t1(producer); // co bao nhieu param thi truyen bay nhieu vao
    thread t2(consumer);

    t1.join();
    t2.join();
    
    return 0;
}
