#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node * createNode(int value){
    //Cap phat bo nho cho bien con tro 
    Node *ptr = (Node*)malloc(sizeof(Node));
    
    ptr->value = value;
    ptr->next=NULL;
    return ptr;
}

void push_back(Node **head, int value){

    if(*head==NULL){
        *head = createNode(value);
    }
    else{
        Node *temp = *head;
        while (temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(value);
    }
}
void push_front(Node **head, int value){
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
void front(Node *head){
    printf("%d \n", head->value);
}
void back(Node *head){
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("%d \n", temp->value);
    
}
int size(Node *head){
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
   return count; 
}
int empty(Node *head){
    if(head == NULL) return 1;
    else return 0;
}
void clear(Node **head){
    *head = NULL;
}
void insert(Node **head, int position, int value){

    Node *newNode = createNode(value);
    Node *temp = *head;
    int i=0;
    while (temp != NULL && i!=(position-1))
    {
        temp = temp->next;
        i++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
}
void erase(Node **head, int position){
    
    Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        temp->next==NULL;
    }
    else{
        int i=0;
        while (temp != NULL && i!=(position-1))
        {
            temp = temp->next;
            i++;
        }
        Node *del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        
    }
    
}
void display(Node *head){
    Node *temp = head;
    while (temp !=NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    Node *ptr = NULL;
    
    if (empty(ptr)) printf("List empty\n");
    else printf("List full\n");

    push_back(&ptr, 2);
    push_back(&ptr, 2);
    display(ptr);
    push_front(&ptr, 3);
    display(ptr);
    front(ptr);
    push_back(&ptr, 2);
    push_back(&ptr, 2);
    display(ptr);
    push_front(&ptr, 5);
    display(ptr);

    front(ptr);
    back(ptr);
    
    if (empty(ptr)) printf("List empty\n");
    else printf("List full\n");
    
    insert(&ptr, 2, 99);
    insert(&ptr, 4, 88);
    display(ptr);

    erase(&ptr, 3);
    erase(&ptr, 3);
    display(ptr);

    clear(&ptr);
    display(ptr);
    if (empty(ptr)) printf("List empty\n");
    else printf("List full\n");
    
}
