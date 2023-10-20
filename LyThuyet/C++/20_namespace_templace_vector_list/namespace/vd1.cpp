#include <iostream>

using namespace std;

namespace conongA{
    int hieu = 1;
}

namespace conongB{
    int hieu = 2;
}
int main(int argc, char const *argv[])
{
    cout << conongA::hieu << endl;

    cout << conongB::hieu << endl;


    return 0;
}
