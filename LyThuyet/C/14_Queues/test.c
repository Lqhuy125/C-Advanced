#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct{
    uint8_t front, rear, size, capacity;
    uint8_t array;
}Queues;

void Queues_Init(Queues *queue, uint8_t capacity){
    queue->array = (uint8_t*)malloc(sizeof(uint8_t) * capacity);
    queue->front = 0;
    queue->size = 0;
    queue->rear = 1;
}
int empty(Queues *queue){
    if(queue->size == 0) return 1;
    else return 0;
}
int full(Queues *queue){
    if(queue->size == queue->capacity) return 1;
    else return 0;
}
int main(int argc, char const *argv[])
{
    Queues queue;
    Queues_Init(&queue, 12);
    
    return 0;
}
