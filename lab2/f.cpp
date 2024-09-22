#include <iostream>
using namespace std;
class Node{
public:    
    int value;
    Node* next;
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;

    }
    void showList(){
        Node* temp = head;
     
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next; 
        }
        
    }

    void InsertAtTheFront(int newValue){
        Node* newNode = new Node();
        newNode->value = newValue;
        newNode->next = head;
        head = newNode;
    }

    void InsertAtTheEnd(int newValue){
        Node* newNode = new Node();
        newNode->value = newValue;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* last = head;
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
    Node* getNode(int pos){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt < pos){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }    

};




int main(){
   LinkedList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        
        int val;
        cin >> val;
        list.InsertAtTheEnd(val);
    }
    int data, pos;
    cin >> data;
    cin >> pos;
    if(pos == 0){
        list.InsertAtTheFront(data);
    }else{
        Node* prev = list.getNode(pos - 1);
        list.insertAfter(prev, data);
    }
    
    list.showList();

    return 0;
}