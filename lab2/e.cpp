#include <iostream>
using namespace std;

class Node{
public:    
    string data;
    Node* next;
    
};




class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = nullptr;
    }
    void add(string s){
        if(head != nullptr){
            head = new Node();
            head->data = s;
        }else if(head->data != s){
            Node* newNode = new Node();
            newNode->data = s;
            newNode->next = head;
            head = newNode;
           
        }
        
    }
    void print(){
        Node* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
            
        }
        cout << "All in all: " << cnt << "\n";
        cout << "Students: \n";
        temp = head;
        while(temp){
            cout << temp->data<<endl;
            temp = temp->next;
        }
    }

    
};



int main(){
    LinkedList list;
    int n;
    cin >> n;
    string a = " ";
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s != a){
            list.add(s);
        }
        a = s;
    }
    list.print();
    return 0;
}
