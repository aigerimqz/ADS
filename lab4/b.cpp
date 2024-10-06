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
    else if(value <= root->data){
        root->left = Insert(root->left, value);

    }
    else if(value > root->data){
        root->right = Insert(root->right, value);
    }
    return root;
}

BstNode* Search(BstNode* root, int value){
    if(root == nullptr || root->data == value){
        return root;
    }
    if(value <= root->data){
        return Search(root->left, value);
    }
    else{
        return Search(root->right, value);
    }
}

int getSubtree(BstNode* root){
    if(root == nullptr){
        return 0;
    }
    return getSubtree(root->left) + getSubtree(root->right) + 1;
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
    int x;
    cin >> x;
    BstNode* subtreeroot = Search(root, x);
    if(subtreeroot != nullptr){
        cout << getSubtree(subtreeroot) << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}