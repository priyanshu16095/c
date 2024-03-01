#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};
struct Node* head;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL) {
        printf("MEMEORY ALLOCATION FAILED");
        return NULL;
    }
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
void insertAtHead(int value) {
    struct Node* node = createNode(value);
    if(head == NULL) {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}
void insertAtEnd(int value) {
    struct Node* node = createNode(value);
    struct Node* temp = head;
    if(head == NULL) {
        head = node;
        return ;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}
void insertAt(int index, int value) {
    struct Node* node = createNode(value);
    if(head == NULL) {
        head = node;
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    for(int i = 0; i < index-1; i++) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = node;
    node->prev = temp1;
    temp2->prev = node;
    node->next = temp2;
}
void deleteAt(int index) {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    for(int i = 0; i < index-1; i++) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2 = temp2->next;
    temp1->next = temp2;
    temp2->prev = temp1;
}
void middleElement() {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while(temp1 != NULL && temp1->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1->next != NULL) {
            temp1 = temp1->next;
        }
    }
    printf("Middle Element: %d\n", temp2->value);
}
void printTail() {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("Tail: %d\n", temp->value);
}
int getAt(int index) {
    struct Node* temp = head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->value;
}
void display() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtHead(7);
    insertAtHead(8);
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    
    insertAtEnd(11);
    insertAt(2, 9);
    
    display();
    
    deleteAt(2);
    display();
    
    middleElement();
    printTail();
}


















