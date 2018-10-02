#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int* array;
};

struct Stack* createStack(unsigned int capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int isNumber(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int isSymbol(char c) {
    if (c == '+') {
        return 1;
    }
    if (c == '-') {
        return 1;
    }
    if (c == '*') {
        return 1;
    }
    if (c == '/') {
        return 1;
    }
    return 0;
}

int isBlank(char c) {
    if (c == ' ') {
        return 1;
    }
    return 0;
}


int main()
{
    struct Stack* stack = createStack(100);
    char msg[100];
    int i = 0;

    gets(msg);

    goto A;

    A:
        if (isNumber(msg[i])) {
            i++;
            goto B;
        } else if (msg[i] == '(') {
            i++;
            goto C;
        } else if (msg[i] == ')') {
            i++;
            goto D;
        } else if (isBlank(msg[i])) {
            i++;
            goto A;
        } else {
            goto reject;
        }
    B:
        if (isEmpty(stack) == 1 && msg[i] == '\0') {
            goto accept;
        } else if (isSymbol(msg[i])) {
            i++;
            goto A;
        } else if (isBlank(msg[i])) {
            i++;
            goto B;
        } else if (msg[i] == ')') {
            i++;
            goto D;
        } else {
            goto reject;
        }

    C:
        if (msg[i] == '\0') {
            goto reject;
        } else {
            push(stack, 'D');
            goto A;
        }
    D:
        pop(stack);
        goto B;

    accept:
        printf("\nAceita");
        exit(0);

    reject:
        printf("\nRejeita");
        exit(0);
}

