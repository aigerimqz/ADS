#include <iostream>
using namespace std;
class Node{
public:
    int value;
    Node* next;
};

class LinkedList{
public:
    Node* head;
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

    void insertAtTheEnd(int newValue){
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


    int countOccur(int val){
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->value == val){
                cnt++;
            }
            temp = temp->next;
        }
        return cnt;
    }


    bool isInList(int val){
        Node* temp = head;
        while(temp != NULL){
            if(temp->value == val){
                return true;

            }
            temp = temp->next;
        }
        return false;
    }

    Node* bubbleSort(){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        int i = 0;
        bool swapped;
        while(i < cnt){
            Node* traverseNode = head;
            Node* prevNode = head;
            swapped = false;
            while(traverseNode->next){
                Node* ptr = traverseNode->next;
                if(traverseNode->value < ptr->value){
                    swapped = true;
                    if(traverseNode == head){
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode = ptr;
                        head = prevNode;
                    }
                    else{
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode->next = ptr;
                        prevNode = ptr;
                    }
                    continue;
                }
                prevNode = traverseNode;
                traverseNode = traverseNode->next;
            }
            if(!swapped){
                break;
            }
            ++i;
        }
        return head;
    }

   

};

int main(){
    LinkedList list, modes;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        list.insertAtTheEnd(val);
    }
    Node* temp = list.head;
    int maxCount = 0;
    while(temp != NULL){
        int cnt = list.countOccur(temp->value);
        if(cnt > maxCount){
            maxCount = cnt;
            modes.head = NULL;
            modes.insertAtTheEnd(temp->value);
        }
        else if(cnt == maxCount && !modes.isInList(temp->value)){
            modes.insertAtTheEnd(temp->value);
        }

        temp = temp->next;
    }
    modes.bubbleSort();
    modes.showList();
    
    return 0;
}