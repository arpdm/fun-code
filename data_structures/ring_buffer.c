#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 10

typedef enum{
    RB_NO_ERROR = 0,
    RB_FULL,
    RB_EMPTY
}RB_Status;

typedef struct{
    uint8_t data[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
} Buffer;

void initBuffer(Buffer* buffer)
{
    buffer->head =0;
    buffer->tail = 0;
}

uint8_t isBufferEmpty(Buffer* buffer)
{
    return (buffer->head == buffer->tail);
}

uint8_t isBufferFull(Buffer* buffer)
{
    return ((buffer->head + 1)% BUFFER_SIZE == buffer->tail);
}

void addToBuffer(Buffer* buffer, uint8_t elem)
{
    if(isBufferFull(buffer))
    {
        printf("Buffer is full.");
        return;
    }

    buffer->data[buffer->head] = elem;
    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
}

uint8_t popFromBUffer(Buffer* buffer)
{
    uint8_t elem = 0;

    if(!isBufferEmpty(buffer)){
        elem = buffer->data[buffer->tail];
        buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
    }
    else{
        printf("Buffer is empty.");
    }

    return elem;
}

int main()
{    
    char str[4];
    Buffer test;

    initBuffer(&test);
    addToBuffer(&test, 1);
    addToBuffer(&test, 2);
    addToBuffer(&test, 3);

    sprintf(str, "%u", popFromBUffer(&test));
    printf("%s\n", str);
    sprintf(str, "%u", popFromBUffer(&test));
    printf("%s\n", str);
    sprintf(str, "%u", popFromBUffer(&test));
    printf("%s\n", str);
    sprintf(str, "%u", popFromBUffer(&test));
    printf("%s\n", str);
    sprintf(str, "%u", popFromBUffer(&test));
    printf("%s\n", str);

    addToBuffer(&test, 1);
    addToBuffer(&test, 2);
    addToBuffer(&test, 3);
    addToBuffer(&test, 4);
    addToBuffer(&test, 5);
    addToBuffer(&test, 6);
    addToBuffer(&test, 7);
    addToBuffer(&test, 8);
    addToBuffer(&test, 9);
    addToBuffer(&test, 10);

}