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
        int cnt = 0;
        node *temp = new node;
        temp->number = number;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        cnt++;
    }
}


void showList(node *current){
    if(isEmpty(current)){
        cout << "The list is empty\n" << endl;

    }
    else{
        int i = 0;
        while(current != NULL){
            if(i % 2 == 0){
                cout << current->number << " ";
            }
            
            current = current->next;
            i++;
        }
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
        insert(head, last, val);
    }
    showList(head);
    
    return 0;
}