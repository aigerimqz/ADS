#include <iostream>
using namespace std;


class List{
private:
    typedef struct node{
        int data;
        node *next;
    } *nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
};

List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;

}


void List::AddNode(int addData){
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else{
        head = n;
    }
}

void List::DeleteNode(int delData){
    nodePtr delPtr = null;
    temp = head;
    curr = head;
    while(curr != NULL && curr->data != delData){
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout << delData << " was not in the list\n";
    }
    else{
        delPtr = curr;
        curr = curr->next
    }
}


int main(){

    return 0;
}
