#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initializeCircularQueue(struct CircularQueue* cqPtr) {
    cqPtr->front = -1;
    cqPtr->rear = -1;
}

int isFull(struct CircularQueue* cqPtr) {
    return (cqPtr->rear+1) % MAX_SIZE == cqPtr->front;
}
int isEmpty(struct CircularQueue* cqPtr) {
    return cqPtr->front == -1;
}
void enqueue(struct CircularQueue* cqPtr, int value) {
    if(isFull(cqPtr)) {
        printf("Queue overflow\n");
        return;
    }
    if(isEmpty(cqPtr)) {
        cqPtr->front = 0;
    }
    cqPtr->rear = (cqPtr->rear+1) % MAX_SIZE;
    cqPtr->arr[cqPtr->rear] = value;
}
int dequeue(struct CircularQueue* cqPtr) {
    if(isEmpty(cqPtr)) {
        printf("Queue underflow\n");
    }
    int value = cqPtr->arr[cqPtr->front];
    if(cqPtr->front ==cqPtr->rear) {
        cqPtr->rear = -1;
        cqPtr->front = -1;
    } else {
        cqPtr->front = (cqPtr->front + 1) % MAX_SIZE;
    }
    return value;
}

void display(struct CircularQueue* cqPtr) {
    if(isEmpty(cqPtr)) {
        printf("Queue is empty\n");
        return;
    }
    int i = cqPtr->front;
    while(i != (cqPtr->rear+1)%MAX_SIZE) {
        printf("%d ", cqPtr->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}


int main() {
   struct CircularQueue cQueue;
   struct CircularQueue* cqPtr = &cQueue;
   initializeCircularQueue(cqPtr);
   enqueue(cqPtr, 7);
   enqueue(cqPtr, 8);
   enqueue(cqPtr, 1);
   enqueue(cqPtr, 2);
   enqueue(cqPtr, 3);
   
   display(cqPtr);
   
   
   printf("%d\n", dequeue(cqPtr));
   display(cqPtr);
}





