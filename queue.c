#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* arr;
    int front;
    int rear;
    int size;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = capacity;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    queue->front = queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}
int isFull(struct Queue* queue) {
    return queue->rear == queue->size-1;
}

void enqueue(struct Queue* queue, int value) {
    if(isEmpty(queue)) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
}
int dequeue(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Empty queue");
        return -1;
    } 
    if(queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return queue->arr[queue->front++];
}
int peak(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Emtpy queue");
        return -1;
    }
    return queue->arr[queue->front];
}
void display(struct Queue* queue) {
    for(int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
}


int main() {
    struct Queue* queue = createQueue(5);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    
    dequeue(queue);
    
    display(queue);
}






