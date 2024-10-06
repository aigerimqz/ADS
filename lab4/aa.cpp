#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

bool checkPath(Node* root, const string& path) {
    Node* current = root;
    
    for (char direction : path) {
        if (direction == 'L') {
            if (current->left) {
                current = current->left;
            } else {
                return false;
            }
        } else if (direction == 'R') {
            if (current->right) {
                current = current->right;
            } else {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    Node* root = nullptr;
    
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }
    
    for (int i = 0; i < M; i++) {
        string path;
        cin >> path;
        
        if (checkPath(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}