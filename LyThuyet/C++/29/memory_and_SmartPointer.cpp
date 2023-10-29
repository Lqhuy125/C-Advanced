#include <iostream>
#include <memory>

using namespace std;

void test_smart_pointer_unique_ptr(){
    unique_ptr<int> var(new int(5)); //Bien 'var' gan gia tri ban dau bang 5

    cout << "var: "<< *var << endl;

    unique_ptr<int[]> var2(new int[10]); //Mang 'var2' voi 10 phan tu

    for (int i = 0; i < 10; i++)
    {
        var2[i] = i;
        cout << "i = " << i << " : "<< var2[i] << endl; 
    }
    //vi sao duoc goi la smart pointer: khi thoat ra khoi block code se auto thu hoi vung nho

    //unique_ptr: 1 con tro chi co the tro den 1 doi tuong
}

void test_smart_pointer_shared_ptr(){
    shared_ptr<int> sptr1(new int(10)); //sptr1 tro den dia chi co gia tri bang 10

    shared_ptr<int> sptr2 = sptr1(); //sptr2 tro den sptr1, cung co gia tri bang 10

    cout << *sptr1 << endl;
    cout << *sptr2 << endl;
    //Shared ptr: 2 con tro tren deu chi den dia tri co gia tri bang 10
}
int main(int argc, char const *argv[])
{
    /* 
        Cap phat dong se duoc luu o phan vung head
        Sau khi su dung xong nen giai phong bo nho bang delete
     */

    //cap phat bo nho dong cho 1 bien
    int *ptr = new int;

    *ptr = 20;

    cout << *ptr << endl;

    //cap phat cho mot mang
    int *array = new int[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = 2*i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "i = " << i << " : "<< array[i] << endl; 
    }
    
    //Thu hoi vung nho
    delete []ptr;

    delete []array;

    /* 
        Cap phat bo nho ( Smart pointer)

     */
    test_smart_pointer();


    return 0;
}
