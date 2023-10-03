#include <iostream>

using namespace std;

template <typename var1, typename var2>
var1 sum(var1 a, var2 b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    cout << sum(1,2) << endl;

    cout << sum(1.1,2.3) << endl;

    cout << sum(1.3,2) << endl;

    cout << sum(1,2.5) << endl;

    return 0;
}
