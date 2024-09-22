#include <iostream>
using namespace std;

class List
{
public:
    List();
    ~List();
private:
    template<typename T>
    class Node{
    public:
        Node *pNext;
        T data;
        Node(T data, Node *pNext){
            this->data = data;
            this->pNext = pNext;
        }

    };

};



int main(){

    return 0;
}