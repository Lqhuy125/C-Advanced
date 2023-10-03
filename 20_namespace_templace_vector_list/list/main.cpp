#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0; 
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    list<int>::iterator it = l.end();
    it--;

    iter_swap(l.begin(), it);

    //insert vao vi tri thu 2
    // list<int>::iterator it;
    // for(it = l.begin(); it != l.end(); it++){
    //     if(count ==  2) l.insert(it, 12);
    //     count++;
    // }

    //display list
    for(it = l.begin(); it != l.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
