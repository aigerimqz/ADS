#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;
};

void printList(Node*n){
    while(n != NULL){
        cout << n->value << endl;
        n = n->next;
    }
}



void insertAtTheFront(Node**head, int newValue){
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = *head;
    *head = newNode;
    
    
}


void insertAtTheEnd(Node**head, int newValue){
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    Node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
}


void insertAfter(Node* prev, int newValue){
    if(prev == NULL){
        cout << "Previous can not be NULL";
        return;
    }

    Node* newNode = new Node();
    newNode->value = newValue;


    newNode->next = prev->next;
    prev->next = newNode;



}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    
    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;
    insertAfter(head, 20);
    printList(head);
    return 0;
}