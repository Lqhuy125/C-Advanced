#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Node
{
    int data;
    struct Node *next
} Node;

typedef struct CenterPoint
{
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

void add_node(Node **head, int value);
CenterPoint *builtTree(Node *head, int start, int end);
CenterPoint *centerPoint(Node *head);
CenterPoint *binarySearch(CenterPoint *root, int value);
void print_list(Node *head);

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    //Tao 10000 so ngau nhien
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }
    //print_list(head);
    add_node(&head, 8543);

    //Xac dinh phan tu o giua list
    CenterPoint *ptr = centerPoint(head);
    
    //Search
    int value = 8543;
    CenterPoint *res = binarySearch(ptr, value);

    if(res != NULL) printf("Tim thay %d\n", res->value);
    else printf("Khong tim thay");

    return 0;
}

/* 
    @brief Add and sort element of linked list
    @param address of head
    @param value of new node
    @return list sorted 
 */
void add_node(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Bo nho chua duoc cap phat\n");
        return 0;
    }
    new_node->data = value;
    new_node->next = NULL;

    /* check xem new_node co la phan tu dau tien hay khong 
        hoac nho hon so dau tien hay khong 
        Neu nho hon thi linked list se co phan tu dau tien 
        la new_node 
    */
    if(*head == NULL || (((*head)->data) >= value) ){
        new_node->next = *head;
        *head = new_node;
        return;
    }
    /* Neu khong thuoc vao cac truong hop tren */
    Node *temp = *head;
    while ( temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;// tạo liên kết cho newnode tới node tiếp theo của node mà con trỏ current đang trỏ tới
    temp->next = new_node; // cho con trỏ của current trỏ tới newnode
}
//tim diem giua phia ben trai va ben phai su dung de quy
CenterPoint *builtTree(Node *head, int start, int end){
    if(head == NULL || start > end){
        return NULL;
    }
    //Di chuyen node den mid
    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++)
    {
        node = node->next;
    }
    
    // tao con tro root tro vao node mid
    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->value = node->data;
    root->left = builtTree(head, start, mid-1);
    root->right = builtTree(node->next, mid+1, end);

    return root;
}

/* 
    @brief tim diem giua
    @param address of linked list
    @return center element of linked list and is added to root 
 */
//tim diem giua va tao cay
CenterPoint *centerPoint(Node *head){
    int length = 0;
    Node *node = head;
    while (node!=NULL)
    {
        length++;
        node = node->next;
    }
    
    return builtTree(head, 0, length-1);
}
/* 
    @brief 
 */
CenterPoint *binarySearch(CenterPoint *root, int value){

    static int loop = 0;
    loop++;
    printf("So lan lap: %d\n", loop);

    // neu root chua duoc khoi tao thanh cong
    if(root==NULL) return NULL;

    /*  neu tim thay value trong root luon thi return luon
        Tra ve so lan lap va display co tim */
    if(root->value == value) return root;

    if(value < root->value) 
        return binarySearch(root->left, value);
    else 
        return binarySearch(root->right, value);
}
/* 
    @brief display linked list
 */
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
