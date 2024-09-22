#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    Node* next;
    Node* prev;
    T key;
public:
    Node(T key){
        this->key = key;
        next  = nullptr;
        prev = nullptr;
    }
    
    Node* getNext(){
        return next;
    }
    Node* getPrev(){
        return prev;
    }
    string getKey(){
        return key;
    }
    void setNext(Node* next){
        this->next = next;
    }
    void setPrev(Node* prev){
        this->prev = prev;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void tail_push(T x){
        Node<T>* newNode = new Node<T>(x);
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
        } else{
            Node<T>* temp = tail;
            tail = newNode;
            temp->setNext(tail);
            tail->setPrev(temp);
        }
    }

    T head_pop(){
        if(head){
            Node<T>* oldHead = head;
            head = oldHead->getNext();
            oldHead->getNext()->setPrev(nullptr);
            T x = oldHead->getKey();
            delete oldHead;
            return x;
        }
        else{
            cout<<"List is empty!"<<endl;
            return T();
        }
    }

    void print(){
        if(head == nullptr && tail == nullptr){
            cout<<"this list is empty"<<endl;
        } else{
            Node<T>* current = head;
            while(current!= nullptr){
                cout<<current->getKey()<<" ";
                current = current->getNext();
            }
            cout<<endl;
            
        }
    }

    

    ~LinkedList(){
        Node<T>* temp;
        if(head!=nullptr){
            temp = head;
            while(temp->getNext()!=nullptr){
                temp = temp->getNext();
                delete temp->getPrev();
                
            }
            delete temp;
            
        }
    }
};