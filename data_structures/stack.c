#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


typedef enum 
{
    ST_NO_ERROR= 0,
    ST_OVERFLOW,
    ST_UNDERFLOW
}ST_STATUS_t;

typedef struct
{
    uint32_t length;
    uint8_t *head;
    uint8_t *base;
    ST_STATUS_t status;
} LIFO_Buf_t;



void initStack(LIFO_Buf_t* stack, uint32_t length)
{
    stack->base = (uint8_t*)malloc(length);
    stack->length = length;
    stack->head = stack->base;
    stack->status = ST_NO_ERROR;
}


void push(LIFO_Buf_t* stack, uint8_t element)
{
    if(stack->head >= (stack->length + stack->base))
    {
        stack->status = ST_OVERFLOW;
        printf("Error: Stack Overflow\n");
        return;
    }

    *stack->head = element;
    stack->head++;
}


uint8_t pop(LIFO_Buf_t* stack)
{
    if (stack->head <= stack->base)
    {
        stack->status = ST_UNDERFLOW;
        printf("Error: Stack Underflow\n");
        return -1;
    }

    uint8_t element = *stack->head;
    stack->head--;
    return *stack->head;
}


uint8_t peek(LIFO_Buf_t* stack)
{
    if (stack->head < stack->base)
    {
        stack->status = ST_UNDERFLOW;
        printf("Error: Stack Underflow\n");
        return -1;
    }
    
    return *stack->head;
}


uint8_t isEmpty(LIFO_Buf_t* stack)
{
    return stack->head < stack->base;
}


void clearStack(LIFO_Buf_t* stack)
{
    free(stack->base);
    stack->base = 0;
    stack->head = 0;
    stack->status = ST_NO_ERROR;
}


int main()
{
    LIFO_Buf_t stack;

    initStack(&stack, 5);
    push(&stack, 7);
    push(&stack, 4);
    push(&stack, 6);
    push(&stack, 8);
    push(&stack, 3);
    push(&stack, 3);

    char str[4];

    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    sprintf(str, "%u", pop(&stack));
    printf("%s\n", str);
    return 0;
}