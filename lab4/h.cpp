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
    }
    else if(value > root->data){
        root->right = Insert(root->right, value);
    }
    return root;
}

void Inorder(BstNode* root, int &sum){
    if(root == nullptr){
        return;
    }
    
    Inorder(root->right, sum);

    sum += root->data;
    cout << sum << " ";
    
    Inorder(root->left, sum);
    
}


int main(){
    BstNode* root = nullptr;
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        
        root = Insert(root, val);
    }
    
    Inorder(root, sum);

    return 0;
}