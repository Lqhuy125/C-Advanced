#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint8_t size, capacity;
    uint8_t *array;
} Stack;

void create_Stack(Stack *stack, uint8_t capacity);
void push(Stack *stack, uint8_t value);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
uint8_t size(Stack stack);
uint8_t top(Stack *stack);

int main(int argc, char const *argv[])
{
    
    Stack ptr;
    create_Stack(&ptr, 6);
    push(&ptr, 12);
    push(&ptr, 1);
    push(&ptr, 3);
    push(&ptr, 2);
    push(&ptr, 4);
    push(&ptr, 5);

    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));

    pop(&ptr);
    printf("top = %d\n", top(&ptr));
    
    printf("empty = %d\n", isEmpty(ptr));
    printf("full = %d\n", isFull(ptr));
    printf("size = %d\n", size(ptr));
    for (uint8_t i = 0; i < ptr.size; i++)
    {
        printf("%d \n", ptr.array[i]);
    }
    
    
}
void create_Stack(Stack *stack, uint8_t capacity){
    stack->capacity = capacity;
    stack->size = 0;
    stack->array = (uint8_t *)malloc(sizeof(uint8_t)*capacity);
}
void push(Stack *stack, uint8_t value){
    if(isFull(*stack)){
        printf("Stack full\n");
        return;
    }
    stack->array[(stack->size)] = value;
    (stack->size)++;
    
    return;
}
void pop(Stack *stack){
    if(isEmpty(*stack)){
        printf("Empty full\n");
        return;
    }
    stack->size --;
}
uint8_t top(Stack *stack){
    return stack->array[stack->size - 1];
}
uint8_t size(Stack stack){
    return stack.size;
}
bool isEmpty(Stack stack){
    if(stack.size == 0) return true;
    else return false;
}
bool isFull(Stack stack){
    if(stack.size == stack.capacity) return true;
    else return false;
}
