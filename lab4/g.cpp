#include <iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int value){
    BstNode* newNode = new BstNode();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BstNode* Insert(BstNode* root, int value){
    if(root == nullptr){
        root = GetNewNode(value);
        return root;
    }
    if(value < root->data){
        root->left = Insert(root->left, value);
    }else if(value > root->data){
        root->right = Insert(root->right, value);
    }
    return root;
}

int maxDistance(BstNode* root, int& distance){
    if(root == nullptr){
        return 0;
    }

    int leftHeight = maxDistance(root->left, distance);
    int rightHeight = maxDistance(root->right, distance);

    distance = max(distance, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);

}

int main(){
    BstNode* root = nullptr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = Insert(root, val);
    }
    int distance = 0;
    maxDistance(root, distance);
    cout << distance + 1 << endl;
    return 0;
}