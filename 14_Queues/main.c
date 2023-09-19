#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    //Truoc, Sau, size, dung luong cho truoc
    uint8_t front, rear, size, capacity;
    uint8_t *array;
}Queues;

void Queues_Init(Queues *queue, uint8_t capacity){
    queue->front = 0;
    queue->size = 0;
    queue->rear = -1;
    queue->array = (uint8_t*)malloc(sizeof(uint8_t)*capacity); 
}

bool isEmpty(Queues *queue){
    if(queue->size == 0) return 1;
    else return 0;
}

bool isFull(Queues *queue){
    if(queue->size == queue->capacity) return 1;
    else return 0;
}

uint8_t front(Queues *queue){
    return queue->array[queue->front];
}

uint8_t rear(Queues *queue)
{
    return queue->array[queue->rear];
}

void enqueue(Queues *queue, uint8_t value){
    if (isFull(queue))
    {
        printf("Queues Full\n");
        return;
    }
    queue->size = queue->size + 1;
    queue->array[++(queue->rear)] = value; 
}
int dequeue(Queues* queue)
{
    if (isEmpty(queue))
    {
        printf("Queues empty\n");
        return 0;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
int main()
{   
    Queues ptr;

    Queues_Init(&ptr, 10);
    enqueue(&ptr, 5);
    enqueue(&ptr, 1);
    enqueue(&ptr, 2);
    enqueue(&ptr, 3);
    enqueue(&ptr, 4);
    enqueue(&ptr, 5);
    enqueue(&ptr, 1);
    enqueue(&ptr, 2);
    enqueue(&ptr, 3);
    enqueue(&ptr, 99);
    printf("size = %d\n", ptr.size);
    printf("%d front from queue\n", front(&ptr));
    printf("%d rear from queue\n", rear(&ptr));
    printf("%d dequeue from queue\n", dequeue(&ptr));
    printf("%d front from queue\n", front(&ptr));
    printf("size = %d\n", ptr.size);
    // for(uint8_t i = 0; i<ptr.size; i++){
    //     printf("%d ", ptr.array[i]);
    // }
    

    return 0;
}
