#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_SIZE 256

typedef struct
{
    uint8_t data[QUEUE_SIZE];
    uint16_t front;
    uint16_t rear;
}Queue;

void initQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

bool isQueueEmpty(const Queue *queue)
{
    return queue->front == queue->rear;
}

bool isQueueFull(const Queue *queue)
{
    return queue->rear == QUEUE_SIZE;
}

void enqueue(Queue *queue, uint8_t element)
{
    if (isQueueFull(queue)) {
        // Queue is full, cannot enqueue element
        return;
    }

    queue->data[queue->rear] = element;
    queue->rear++;
}

uint8_t dequeue(Queue *queue)
{
    if (isQueueEmpty(queue)) {
        // Queue is empty, nothing to dequeue
        return -1;
    }

    uint8_t element = queue->data[queue->front];    
    
    // Shift all elements forward one position
    for (int i = queue->front; i < queue->rear - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }

    queue->rear--;
    return element;
}

int main()
{    
    char str[4];
    Queue test;

    initQueue(&test);
    enqueue(&test, 1);
    enqueue(&test, 2);
    enqueue(&test, 3);

    sprintf(str, "%u", dequeue(&test));
    printf("%s\n", str);
    sprintf(str, "%u", dequeue(&test));
    printf("%s\n", str);
    sprintf(str, "%u", dequeue(&test));
    printf("%s\n", str);
    sprintf(str, "%u", dequeue(&test));
    printf("%s\n", str);
    sprintf(str, "%u", dequeue(&test));
    printf("%s\n", str);
}