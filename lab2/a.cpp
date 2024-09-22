#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int findNearest(int target) {
        if (head == nullptr) return -1;

        Node* temp = head;
        int ni = 0;
        int i = 0;
        int mini = abs(temp->data - target);

        while (temp != nullptr) {
            int len = abs(temp->data - target);
            if (len < mini) {
                mini = len;
                ni = i;
            }
            temp = temp->next;
            i++;
        }

        return ni;
    }
};

int main() {
    int n, target;
    cin >> n;

    LinkedList list;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list.add(value);
    }

    cin >> target;

    cout << list.findNearest(target) << endl;

    return 0;
}
