#include <iostream>
#include <vector>

using namespace std;

void test(vector<int> &v){
    v[1] = 10;
} 
void printf(vector<int> v){
    for(int x : v){
        cout << x << endl;
    }
}
int main(int argc, char const *argv[])
{
    vector <int> v = {1,2,3};

    //cout << v.at(1);

    // for(int x : v){
    //     cout << x << endl;
    // }

    //v.push_back(6);

    // v.erase(v.begin()); //xoa vi tri dau tien. xoa dia chi
    //v.erase(v.begin()+1);  //xoa vi tri thu 1. giong kieu con tro tro

    test(v);
    printf(v);


    return 0;
}
