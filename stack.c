#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* arr;
    int top;
    int size;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(stack == NULL) {
        printf("MEMORY ALLOCATION FAILED");
        return NULL;
    }
    stack->size = capacity;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == stack->size-1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int value) {
    if(isFull(stack)) {
        printf("STACK OVERFLOW");
        return;
    }
    stack->arr[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("STACK UNDERFLOW");
        return -1;
    }
    return stack->arr[stack->top--];
}
int peak(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("Empty stack");
        return -1;
    }
    return stack->arr[stack->top];
}
void display(struct Stack* stack) {
    for(int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack(5);
    push(stack, 7);
    push(stack, 8);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    
    display(stack);
    
    int poppedItem = pop(stack);
    printf("%d\n", poppedItem);
    
    int peakedItem = peak(stack);
    printf("%d\n", peakedItem);
    
    display(stack);
}














