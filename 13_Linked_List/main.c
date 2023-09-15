#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *next; 
}Node;

Node *createNode(int value);

int size(Node *head);
void display(Node *head);
void front(Node *head);
void back(Node *head);
void push_back(Node **ptp, int value);
void push_front(Node **ptp, int value);
void insert(Node **head, int position, int value);
int empty(Node *head);
void erase(Node **head, int position);
void clear(Node **head);

int main(int argc, char const *argv[])
{

    Node *ptr = NULL;
    //để gán ptr ban đầu là NuLL tới 1 địa chỉ khác
    //Lúc này *ptr trỏ đến con trỏ khác
    //=> Pointer to pointer
    push_back(&ptr, 7);
    push_back(&ptr, 3);
    display(ptr);
    clear(&ptr);

    push_back(&ptr, 1);
    push_back(&ptr, 3);
    push_back(&ptr, 8);
    push_back(&ptr, 5);
    erase(&ptr, 2);
    display(ptr);

    printf("size of Linked List: %d\n", size(ptr));
    front(ptr);
    back(ptr);

    insert(&ptr, 2, 99);
    display(ptr);

    printf("Linked list after add element at the begin\n");
    push_front(&ptr, 99);
    display(ptr);
}

/* 
    @brief Add elements 
*/
void push_back(Node **ptp, int value){
     if(*ptp == NULL){
        *ptp = createNode(value);
     }
     else{
        Node *temp = *ptp;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(value);  
     }
}
/* 
    @brief Create Node new

    Return: address
 */
Node *createNode(int value){
    Node *ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Bo nho chua duoc cap phat\n");
        return 0;
    }
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
    //Trả về 1 địa chỉ
}

/* 
    @brief get size Linhked List
 */
int size(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
/* 
    @brief Display Linhked list
 */
void display(Node *head){
    if(empty(head)){
        printf("List empty\n");
        return;
    }
    
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
/* 
    @brief Returns the value of the first element in the list.
 */
void front(Node *head){
    if(empty(head)){
        printf("List empty\n");
        return;
    }
    else{
        printf("the value of the first element: %d\n", head->value);
    }
}

/* 
    @brief Returns the value of the last element in the list.
 */
void back(Node *head){
    Node * currentElement = head;
    if(currentElement == NULL){
        printf("List empty\n");
        return;
    }
    while(currentElement->next != NULL)
    {
        currentElement = currentElement->next;
    }
    //return currentElement;
    printf("the value of the last element: %d\n", currentElement->value);
}

/* 
    @brief Inserts new elements in the list before the element at a specified position.
 */
void insert(Node **head, int position, int value){

    if(position>size(*head)){
        printf("Position k hop le\n");
        return;
    }
    Node *temp = *head;
    int i=0;
    while (temp->next != NULL && i != (position-1))
    { 
        temp = temp->next;
        i++;
    }
    Node *p = createNode(value);
    p->next = temp->next;
    temp->next = p;
}

/* 
    @brief Adds a new element ‘g’ at the beginning of the list.
 */
void push_front(Node **head, int value){
    
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
/* 
    @brief Check list if the list is empty(1) or not(0).
 */
int empty(Node *head){
    if(head==NULL) return 1;
    else return 0;
}
/* 
    @brief Delete element 
 */
void erase(Node **head, int position){

    Node *temp = *head;
    
    if(position == 0){
        *head = temp->next;
        temp->next = NULL;
    }
    else{
        int i = 0;
        while(temp->next!=NULL && i!=(position-1))
        {
            temp = temp->next;
            i++;
        }
        Node *del = temp->next;
        temp->next = del->next;
        del->next=NULL;
        
    }
}

/* 
    @brief Clear
 */
void clear(Node **head){
    *head = NULL;
    
}