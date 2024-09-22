#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){

    if(p == 0){
        node->next = head;
        return node;

    }

    
    Node* curr = head;
    for(int i = 0; i < p - 1; i++){
        if(curr == nullptr){
            return head;
        }
        curr = curr->next;
    }
  
    
    node->next = curr->next;
    curr->next = node;
    
    return head;
    
    
    
}
 
Node* remove(Node* head, int p){
    if (p == 0 && head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    
    Node* curr = head;
    for(int i = 0; i < p - 1; i++){
        if(curr == nullptr || curr->next == nullptr){
              return head;
        }
        curr = curr->next;
    }
    Node* temp = curr->next;
    if(temp != nullptr){
        curr->next = temp->next;
        delete temp;
    }
    
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node* curr = head;
    Node* removedNode = nullptr;
    int removedVal;

    if(p1 == 0){
        removedVal = head->val;
        head = remove(head, p1);
    }
    else{
        Node* prev = head;
        for(int i = 0; i < p1 - 1; i++){
            prev = prev->next;
        }
        removedNode = prev->next;
        removedVal = removedNode->val;
        head = remove(head, p1);
    }
    head = insert(head, new Node(removedVal), p2);
    return head;
  
}
 
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
void print(Node* head){
    Node* temp = head;
    if(head == NULL){
        cout << -1;
       
    }else{
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x) {
    if (x == 0 || head == nullptr) {
        return head;
    }

    Node* curr = head;
    int length = 1;
    while (curr->next != nullptr) {
        curr = curr->next;
        length++;
    }

    x = x % length;
    if (x == 0) {
        return head;
    }

    curr = head;
    for (int i = 1; i < x; i++) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = nullptr;

    curr = newHead;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (x == 0 || head == nullptr) {
        return head;
    }

    Node* curr = head;
    int length = 1;
    while (curr->next != nullptr) {
        curr = curr->next;
        length++;
    }

    x = x % length;
    if (x == 0) {
        return head;
    }

    curr = head;
    for (int i = 1; i < length - x; i++) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = nullptr;

    curr = newHead;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = head;

    return newHead;
}

 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
          
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}