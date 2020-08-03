#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node * front =NULL;
Node * rear = NULL;


void enqueue(int x){
    Node *newptr = new Node;
    
    if (newptr == NULL){        // full check
        printf("FULL, Heap is full!");
    }
    else{
        newptr->data=x;
        newptr->next=NULL;
        
        if (front == NULL){     // empty check
            front = newptr;
            rear = newptr;
        }
        else {
        rear->next = newptr;
        rear= newptr;
        }
    }
}

int dequeue(void){
    
    if (front == NULL){
        printf("Empty!");
    }
    else {
    int x =front->data;
    Node * tmpptr =front;
    
    front = front-> next;
    free(tmpptr);
    
    return x;
    }
}

void displayqueue(Node *temp){
    
        while(temp!=NULL){
        printf("val is %d \n", temp->data);
        temp=temp->next;
    }
}


int main()
{
    printf("Hello World \n");
    
    enqueue(10);
    enqueue(15);
    enqueue(5);
    enqueue(12);
    enqueue(2);
    
    Node * temp = front;
    
    displayqueue(temp);
    
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());    
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());
    
    return 0;
}
