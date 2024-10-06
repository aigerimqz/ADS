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
    if(value <= root->data){
        root->left = Insert(root->left, value);
    }else{
        root->right = Insert(root->right, value);
    }
    return root;
}

bool IsTriangle(BstNode* root){
    if(root == nullptr){
        return false;
    }
    return(root->left && root->right);
 
}

int totalTriangles(BstNode* root){
    if(root == nullptr){
        return 0;
    }
    int cnt = 0;
    if(IsTriangle(root)){
        cnt++;
    }
    cnt += totalTriangles(root->left);
    cnt += totalTriangles(root->right);
    
    return cnt;
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
    cout << totalTriangles(root);
    return 0;
}