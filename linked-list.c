#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
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
    if(head == NULL) {
        head = node;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}
void insertAt(int index, int value) {
    struct Node* node = createNode(value);
    if(head == NULL) {
        head = node;
        return;
    }
    struct Node* temp = head;
    for(int i = 0; i < index-1; i++) {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}
int size() {
    int count;
    struct Node* temp = head;
    while(temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void deleteAt(int index) {
    if(index > size() || index < 0) {
        printf("Invalid index");
        return;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    for(int i = 0; i < index-1 ; i++) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = NULL;
}

void reverseList() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* temp = NULL;
    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
struct Node* reversedCopy() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* temp = NULL;
    struct Node* newHead = NULL;
    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    newHead = prev;
    return newHead;
}

void middleElement() {
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while(temp1 != NULL && temp1->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1->next != NULL) {
            temp1 = temp1->next;
        }
    }
    if(temp2 != NULL) {
        printf("Middle Element: %d\n", temp2->value);
        return;
    }
    printf("Empty list");
}
int nodeFromEnd(int index) {
    if(head == NULL) {
        printf("Empty list");
        return -1;
    }
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    for(int i = 0; i < index; i++) {
        if(temp2 == NULL) {
            printf("List has less %d nodes", index);
            return -1;
        }
        temp2 = temp2->next;
    }
    while(temp2 != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->value;
}

void display() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteMiddle() {
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while(temp1 != NULL && temp1->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1->next != NULL) {
            temp1 = temp1->next;
        }
    }
    struct Node* temp3 = head;
    while(temp3->next != temp2) {
        temp3 = temp3->next;
    }
    temp3->next = temp3->next->next;
    temp2->next = NULL;
}

void convertToCircular() {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
}
void displayCircular() {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    struct Node* temp = head;
    while(1) {
        printf("%d -> ", temp->value);
        temp = temp->next;
        if(temp == head) {
            break;
        }
    }
    printf("HEAD\n");
}
void splitCircular() {
    struct Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void isPallindrome() {
    struct Node* temp1 = head;
    struct Node* temp2 = reversedCopy();
    while(temp1 != NULL) {
        if(temp1->value != temp2->value) {
            printf("False");
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    printf("True");
}

int main() {
    insertAtHead(7);
    insertAtHead(8);
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(9);

    display();
    
    middleElement();
    
    int eleFromEnd = nodeFromEnd(2);
    printf("Node from last: %d\n", eleFromEnd);
    
    deleteMiddle();
    display();
    
    convertToCircular();
    displayCircular();
    splitCircular();
    
    
}
