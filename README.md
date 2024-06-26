## PROGRAMMING C

<details>
<summary><h3>0. C basic<h3></summary>
 <ul>
 <details>
	 
<summary><h4> 0.1 Data Type <h4></summary>

- Some common data types(in library **stdint.h**):

	| Data Type  | Size (bytes) | Range | 
  	|:-------:|:--------:|:--------:|
  	|int8|1 byte |-128 to 127|
	|uint8_t |1 byte |0 to 255|
	|int16_t |2 bytes |-32768 to 32767|
    |uint16_t|2 byte |0 to 65535|
    |int32_t |2 byte |-2147483648 to 2147483647|
    |uint32_t|4 bytes |0 to 4294967295|
    |int64_t |8 bytes |-9223372036854775808 to 9223372036854775807|
    |uint64_t|8 bytes |0 to 18446744073709551615|
  
</details>
<details>
<summary><h4> 0.2 Typedef <h4></summary>

- Typedef được sử dụng để đặt tên mới cho kiểu dữ liệu.
## Example:
```c
#include <stdio.h>
typedef int typeInt; //typeInt can be used in place of int
int main()
{
    typeInt a = 10;
    printf("%d ", a);
    return 0;
}
```
</details>

<details>
<summary><h4> 0.3 C Control Statements <h4></summary>

- C if...else Statement
- Switch Statement in C
- C for Loop
- While and do...while loop in C
- Switch case (combine Enum)

  <details>
	<summary>Example</summary>

    ```c
    #include <stdio.h>
    typedef enum{
        THANG_MOT,
        THANG_HAI,
        THANG_BA,
        THANG_BON,
        
    } thang_t;
    
    int main(){
        thang_t thang;
        switch (thang)
        {
            case THANG_MOT:
            case THANG_BA:
                /* code */
                break;
            case THANG_HAI:
                /* code */
                break;
            case THANG_BON:
                /* code */
                break;
            default:
                printf("Error\n")
                break;
        }
    }
    ```
- Continue
- Break
  </details>
</details>

<details>
<summary><h3>1. Compiler<h3></summary>
 <ul>
	 
  **Quá trình biên dịch:**
  
![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)
 	
   Bắt đầu từ file ` *.c/ *.h ` ( được gọi là ***Source file***). Ex: main.c
   
   Sau khi qua quá trình tiền xử lý(***Preprocessor***), file ` *.c/ *.h ` chuyển thành file ` *.i ` ( được gọi là ***Preprocessed Sources***). Ex: main.i
   ```c
gcc -E main.c -o main.i
 ```
   Sau đó chuyển sang quá trình ***Compiler*** sẽ biến file `*.i` thành file `*.s` ( được gọi là ***Assemply Code*** ). Ex: main.s
   ```c
gcc main.i -S -o main.s
 ```
   Tiếp đến là quá trình ***Assembler*** sẽ biến file `*.s` thành file `*.o` (được gọi là ***Object files***). Ex. main.o
   ```c
gcc -c main.s -o main.o
 ```
   
   Cuối cùng là quá trình ***Linker*** sẽ kết hợp file `*.o` và các Libraries lại với nhau tạo thành file `*.exe` (được gọi là ***Executable***). Ex. main.exe
   ```c
gcc main.o -o main
 ```
How to run file `main.exe` using cmd: ` ./main.exe ` or ` ./main `
</details>

<details>
<summary><h3>2. Macro <h3></summary>
 <ul>
<details>
<summary><h4> 2.1 #define <h4></summary>
<ul>
<details>
<summary><h4> 2.1.1 Expression <h4></summary>
	
**Example**:	
```c
#define SUM(a, b) (a + b)
```
</details>
<details>
<summary><h4> 2.1.2 CREATE FUNCTION <h4></summary>
	
**Example**:	
```c
#define CREATE_FUNC1(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)cmd);       \
    } 
/* 
    Co the su dung ` # `. Sau ` # ` se la chuoi nen se khong can ` "" ` 
 */
#define CREATE_FUNC2(name, cmd)         \
    void name(){                        \
        printf("%s", (char*)#cmd);      \
    } 
// # to inform that "#cmd" is a string 

CREATE_FUNC1(test1, "This is test 1\n");
CREATE_FUNC1(test2, "This is test 2\n");
CREATE_FUNC2(test3, This is test 1\n); 
CREATE_FUNC2(test4, This is test 2\n);

int main(){
    test1();
    test2();
    test3();
    test4();
}
```

</details>
<details>
<summary><h4> 2.1.3 CREATE VARIABLE <h4></summary>

**Example**:	
```c
    #define CREATE_VARIABLE(name)           \
    int     int__##name;                    \
    double  double__##name;                 \
    char    char__##name 

    // \ used for Line break and the last one don't use
    // ## to connect two string 

    CREATE_VARIABLE(var1);
```
Biến sẽ được khởi tạo thành: 
```c
int int__var1; double double__var1; char char__var1;
```

</details>
<details>
<summary><h4> 2.1.4 Variadic in C <h4></summary>
Reference Documents: https://www.geeksforgeeks.org/variadic-functions-in-c/	

**Example:**
```c
#define VAR(...) __VA_ARGS__   //__VA_ARGS__ will be replaced by anything in (...)
int main(){
	VAR(hello world)
	VAR(int a, int b, int c);
}
```
Output:
``` 
hello world
int a, int b, int c;
```

</details>
</details>	

<details>	
<summary><h4> 2.2 #ifndef ... #endif <h4></summary>
ifndef: if not define
	
Thường được sử dụng để tránh việc define một tên nhiều lần

**Example:**
```c
#ifndef SIZE
/* 
    Neu SIZE chua duoc dinh nghia thi doan nay se duoc su dung 
 */
#define SIZE 5  

#endif
```
</details>

<details>
<summary><h4> 2.3 #if ... #elif... #else... #endif <h4></summary>

**Example:**
```c
#define SIZE 22

#if SIZE > 20
    void display(){
        printf("Size > 20\n");
    }
    
#elif SIZE == 20
    void display(){
        printf("Size = 20\n");
    }
#else SIZE < 20
    void display(){
        printf("Size < 20\n");
    }
#endif
```
</details>
  
 </details>

<details>
<summary><h3>3. Pointer<h3></summary>
<ul>

***Pointer*** can be used to store memory address of variable, function and other pointer
<details>
<summary><h4>3.1 Pointer<h4></summary>
<ul>
	
**Syntax:**
```c
datatype * ptr;
```

**Example:**
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;

    int * ptr = &a;

    printf("Address of a: %p\n", &a); 			//Address of a: 000000b66e5ff6dc

    printf("Address of pointer: %p\n", &ptr); 		//Address of pointer: 000000b66e5ff6d0
    printf("Value of pointer: %p\n", ptr);		//Value of pointer: 000000b66e5ff6dc
    printf("Value of variable pointer: %d\n", *ptr);	//Value of variable pointer: 10

    return 0;
}
``` 
</details>

<details>
<summary><h4>3.2 NULL Pointer<h4></summary>
<ul>

- Khi khai báo một biến con trỏ cần gán cho nó một địa chỉ. Nếu chưa sử dụng thì nên gán địa chỉ NULL
- Khi sử dụng xong 1 biến con trỏ cũng nên gán trả lại NULL
  
=> Tránh việc con trỏ trỏ tới một địa chỉ ngẫu nhiên mà chương trình đang sử dụng gây sai lệnh or nhầm lẫn

**Syntax:**
```c
data_type *pointer_name = NULL;
        or
pointer_name = NULL
```
</details>
	
<details>
<summary><h4>3.3 Function Pointer<h4></summary>
<ul>
	
 **Syntax:**
```c
datatype (*ptr) ( para_type_1, para_type_2, ...); //Khai bao con tro ham
ptr = &function();			    	  //Gan dia chi cua ham cho con tro

or

((func_data_type (*)(func_para_type_1, func_para_type_2, ...))name_func)(value_input, ...)
```
**Example:**
```c
#include <stdio.h>
void tong(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}
void hieu(int a, int b){
    printf("%d - %d = %d\n", a, b, a-b);
}
int Tich(int a, int b){
    return a*b;
}
void TinhToan(int a, int b, void (*ptr)(int a, int b)){
    printf("Ham tinh toan:\n");
    ptr(a, b);
}
int main(int argc, char const *argv[])
{
/*
*  @brief Cach 1
*/
    void (*ptr)(int, int);
    ptr = &tong;
    ptr(9,7);

    int (*ptrTich)(int, int) = &Tich;
    printf("%d\n", ptrTich(5, 5));

    void (*ptrTinhtoan)(int, int, void(*));
    ptrTinhtoan = &TinhToan;
    ptrTinhtoan(2, 4, tong);
/*
*  @brief Cach 2
*/
   ((void (*)(int, int))tong)(9, 7);

   printf("Tich: %d", ((int (*)(int, int))Tich)(5, 5));
	
   ((void (*)(int, int, void(*)))TinhToan)(2, 4, tong);

/*
*  @brief Using Function Pointer to caculator
*/
   TinhToan(1, 2, &tong);
   TinhToan(3, 2, &hieu);
}
```
</details>

<details>
<summary><h4>3.4 Void Pointer<h4></summary>
<ul>

 **Syntax:**
```c
void * pointer_name;
```
**Example:**
```c
#include <stdio.h>

int tong(int a, int b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    void *ptr;
    int i = 10;
    double d = 1.1;
    char c = 'c';
    
    ptr = &i;
    printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int *)ptr);

    ptr = &d;
    printf("Dia chi: %p, Gia tri: %f\n", ptr, *(double *)ptr);

    ptr = &c;
    printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char *)ptr);

    ptr = &tong;
    printf("Dia chi: %p\n", ptr);
    printf("Gia tri: %d\n", ((int (*)(int, int))ptr)(1,2));
}
```
**Output:**
```
Dia chi: 000000ede39ffa64, Gia tri: 10
Dia chi: 000000ede39ffa58, Gia tri: 1.100000
Dia chi: 000000ede39ffa57, Gia tri: c
Dia chi: 00007ff6f4311591
Gia tri: 3
```

</details>

<details>
<summary><h4>3.5 Pointer to Pointer<h4></summary>
<ul>

**Example:**
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr = &a;
    int **ptp = &ptr;

    printf("Addr of a: %p\n", &a);
    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d\n", &ptr, ptr, *ptr);

    printf("Addr_ptr: %p Val_ptr: %p Val_var_ptr: %d", &ptp, ptp, **ptp);
    return 0;
}
```
**Output:**
```c
Addr of a: 000000b82e5ff66c
Addr_ptr: 000000b82e5ff660 Val_ptr: 000000b82e5ff66c Val_var_ptr: 10
Addr_ptp: 000000b82e5ff658 Val_ptp: 000000b82e5ff660 Val_var_ptp: 10
```
</details>
</details>

<details>
<summary><h3>4. Variable<h3></summary>
	
![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Storage-Classes-In-C.png)

<ul>
<details>
<summary><h4>4.1 Static <h4></summary>
<ul>

	- Ứng dụng khi code MCU: VD Chạy hàm Init() 1 lần duy nhất rồi sau đó k chạy hàm Init() lần nào nữa
</details>

<details>
<summary><h4>4.2 Extern <h4></summary>
	
- Có thể sử dụng variable/function của file khác:
  
```c
main.c
#include <stdio.h>

extern int x;
int main(){
	printf("%d\n", x); // return 10
}
```

```c
main.h
#include <stdio.h>

int x = 10;
```
<ul>
 
</details>

<details>
<summary><h4>4.3 Register <h4></summary>
	
```c
- biến lưu ở CPU register có tốc độ xử lý nhanh hơn biến lưu ở RAM 
nhưng bộ nhớ Register có giới hạn nên chỉ sử dụng khi nào cần thiết
- Can't get the address of the register variable.
```
</details>

<details>
<summary><h4>4.4 Volatile <h4></summary>

- Thông báo cho compiler không tối ưu hàm đã được khởi tạo sẵn( sử dụng giá trị đã được khởi tạo từ trước)

 	- Tránh xảy ra lỗi do tính năng optimization của compiler
  	- VD: Trong Embedded nếu biến count để đếm số lần ngắt ngoài 
   	      thì có thể không cập nhật vì biến count không bị thay đổi bởi phần mềm

```c
volatile int count;

void ISR() {
count++;
}

int main() {
while (1) {
// do something
}
return 0;
}
```
<ul>
</details>
</details>
 
<details>
<summary><h3>5. Phân vùng nhớ<h3></summary>

**Phân vùng trong RAM:**
![alt text](https://github.com/Lqhuy125/C-Advanced/blob/master/LyThuyet/C/5_Phan_Vung_Nho/Phanvungnho.png)

<ul>
<details>
<summary><h4>5.1 Text<h4></summary>
<ul>
	
	- Chỉ có quyền Read 
 
	- Chứa lệnh thực thi chương trình
 
	- Chứa các khai báo hằng số trong chương trình. vd: const int x = 10;

 **Note:**
```c
Khi mà chương trình nạp vào con vxl nó sẽ lưu vào trong phân vùng flash(thông tin sẽ k bị mất đi kể cả khi mất nguồn).
VD: như những phần mềm có ở trên máy, nó được lưu ở phân vùng flash.
Vì khi đó tắt nguồn mở lên thì dữ liệu vẫn sẽ còn.
Khi click vào để run program, thì source code của chương trình đang
được lưu ở flash nó sẽ coppy sang RAM( phân vùng text) để chạy
```
</ul>
</details>

<details>
<summary><h4>5.2 Data<h4></summary>
<ul>
	
	- Quyền truy cập là Read/Write. 
	
	- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
 
	- Được giải phóng khi kết thúc chương trình. 

</ul>
</details>

<details>
<summary><h4>5.3 bss<h4></summary>
<ul>
	
	- Quyền truy cập là Read/Write.
	
	- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
 
	- Được giải phóng khi kết thúc chương trình.

</ul>
</details>

<details>
<summary><h4>5.4 Heap<h4></summary>
<ul>
	
	– Quyền truy cập là Read/Write.
	
	– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
 
	– Sẽ được giải phóng khi gọi hàm free,…

**Example:**
```c
//malloc/calloc return void* => can ep kieu

uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*5);  //cap phat bo nho

ptr = (uint16_t*)realloc(ptr, sizeof(uint16_t)*7); 	//thay doi bo nho cua mang truoc do

free(ptr);						//Giai phong vung nho 
```
</ul>
</details>

<details>
<summary><h4>5.5 Stack<h4></summary>
<ul>
	
	– Quyền truy cập là Read/Write.
	
	– Được sử dụng cấp phát cho biến local, input parameter của hàm,…	
 	
	– Sẽ được giải phóng khi ra khỏi block code/hàm
 **Note:** 
- Dù là hằng số nhưng nếu được khai báo trong hàm bất kì( biến này sẽ trở thành biến cục bộ)
=> biến này sẽ được lưu vào phân vùng **Stack**

**Example:**
```c
void func(int a, int b){
    int c = a + b;
    printf("%d\n", c);
    //Note
    const int i = 10;           // SE DUOC LUU TAI PHAN VUNG STACK 
                                // VI LA BIEN CUC BO MAC DU LA HANG SO
}
```
</ul>
</details>

**Note: So sánh Heap và Stack**
- Đều là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi
- Stack: Lưu biến cục bộ, tham số truyền vào hàm. Heap: Lưu vùng nhớ cho các biến con trỏ cấp phát động
- Kích thước vùng nhớ:(cố định hay không cố định)
- Dặc điểm vùng nhớ: (Quản lý ntn? Bởi ai? Vùng nhớ sẽ ảnh hưởng ntn sau khi thực hiện/hành động 1 quá trình nào đó?)

</details>

<details>
<summary><h3>6. va_args<h3></summary>
<ul>

***Syntax:*** 
```c
int function_name(data_type variable_name, ...);
```    
- Để gọi được hàm này cần khai báo thư viện: `#include <stdarg.h>`
  
    **Example:**
    ```c
    #include <stdio.h>
    #include <stdarg.h>

    int findMin(int num, ...){
        int tmp = 0, min;

        va_list va;                     //va_list is a type to hold information about variable argument
        
        va_start(va, num);              //va_start must be called before accessing variable argument list

        min = va_arg(va, int);          //Now arguments can be accessed one by one
                                        //Here, va_arg is accessed first argument in list


        for (int i = 1; i < num; i++)               //do something with va_arg()
            if( (tmp = va_arg(va, int)) < min)
                min = tmp;
        
        va_end(va);                     //va_end should be executed before the function returns

        return min;

    }

    int main(int argc, char const *argv[])
    {
        printf("Min in list: %d\n", findMin(5, 4, 67, 6, 7, 1));
        return 0;
    }
    ```
    
</details>

<details>
<summary><h3>7. Goto and Setjump<h3></summary>
<ul>
<details>
<summary><h4>7.1 Goto<h4></summary> 

**Syntax:** 
```
Syntax1      |   Syntax2
----------------------------
goto label;  |    label:  
.            |    .
.            |    .
.            |    .
label:       |    goto label;
```
**Note:**

- Thường được sử dụng để break các vòng lặp lồng nhau.
    
    VD: Có 3 vòng lặp lồng nhau, khi break 1 vòng lặp thì nó sẽ ra vòng lặp bên ngoài. 
    
    => sử dụng goto sẽ hợp lý hơn
- Chỉ sử dụng được trong phạm vi 1 function
</details>


<details>
<summary><h4>7.2 Setjump<h4></summary>

- setjump and longjump are defined in ***setjmp.h***
 
**Syntax:** 
```c
jmp_buf buf; //Khai bao buf

setjump(buf); //uses buf to remember the current position and returns 0.

longjump(buf, i); //when call this func will Go back to the place buf (setjump) is pointing to and return i.
``` 
**Note:**

- Có thể sử dụng để làm biến toàn cục
</details>

</details>


<details>
<summary><h3>8. Bit mask<h3></summary>
<ul>

- dich trai
- dih phai
- phep or
- phep and
- dao bit

vd: sd bit mask kiem tra gio hang xem co cac mat hang nao

cac mat hang su dung enum de thiet ke

**Note:**
- clear bit: giohang &= ~ao
- set: giohang |= ao

- check bit: dulieucanCheck  & (1 << vi tri can kiem tra)

    == 0 thi bit tai vitriCheck = 0

    !=0  thi bit tai vitriCheck = 1
</details>

<details>
<summary><h3>9. Áp dụng setjump trong Try Catch<h3></summary>
<ul>

</details>

<details>
<summary><h3>13. Linked List<h3></summary>
<ul>

- Phần từ của Linked List là các node: list = {node1, node2, ...}
- 1 node bao gồm: 
    + Giá trị của nó (value)
    + địa chỉ của node tiếp theo (next)

- Node cuối cùng sẽ có địa chỉ next = NULL
- Địa chỉ của list sẽ là địa chỉ của phần tử đầu tiên
- Địa chỉ của các phần của Linked List là địa chỉ ngãu nhiên (Không liền kề như địa chỉ của các phần tử array)

</details>

<details>
<summary><h3>14. Queues<h3></summary>
<ul>
    -FIFO
</details>

<details>
<summary><h3>16. Stacks<h3></summary>
<ul>
    - LIFO
</details>

<details>
<summary><h3>17. BinarySearch<h3></summary>
<ul>
    - 
</details>

<details>
<summary><h3>19. Class<h3></summary>
<ul>
Cấu trúc:

     - tương tự struct


Địa chỉ: 

    - Phần tử đầu tiên của class chính lằ địa chỉ của class đó.
    - Địa chỉ các phần tử tiếp theo cộng dần phụ thuộc vào kích thước của kiếu dữ liệu

Trong class chỉ nên định nghĩa các property và các method, còn nên triển khai ở ngoài

Sử dụng:

    - <kiểu(void/int)><tên_class>::<tên_method(property)>

```c
int SinhVien::mssv;
void SinhVien::display()
```
</details>

<details>
<summary><h3>20. Namespace<h3></summary>
<ul>

</details>
