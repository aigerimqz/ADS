#include <iostream>
using namespace std;

struct node{
    int number;
    node *next;
};

bool isEmpty(node *head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

void insertAsFirstElement(node *&head, node *&last, int number){
    node *temp = new node;
    temp->number = number;
    temp->next = NULL;
    head = temp;
    last = temp; 
}
void insert(node *&head, node *&last, int number){
    if(isEmpty(head)){
        insertAsFirstElement(head, last, number);
    }
    else{
        node *temp = new node;
        temp->number = number;
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }
}

int main(){
    node *head = NULL;
    node *last = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        insert(val);
    }
    return 0;
}