#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList{
    Node* head;
    LinkedList(){
        this->head = NULL;
    }

    void append(Node* newNode){
        
    }

};





int main(){
    return 0;
}