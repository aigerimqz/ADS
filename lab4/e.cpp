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

BstNode* Insert(BstNode* root, int x, int y, int z){
    if(root == nullptr){
        return root;
    }
    if(root->data == x){
       if(z == 0){
        root->left = GetNewNode(y);
       }else{
        root->right = GetNewNode(y);
       }
    }else{
        root->left = Insert(root->left, x, y, z);
        root->right = Insert(root->right, x, y, z);
    }
    return root;
}

int FindHeight(BstNode* root){
    if(root == nullptr){
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int countNodes(BstNode* root, int level){
    if(root == nullptr){
        return 0;
    }
    if(level == 0){
        return 1;
    }
    else{
        return countNodes(root->left, level - 1) + countNodes(root->right, level - 1);
    }
}

int getMaxWidth(BstNode* root){
    int maxwidth = 0;
    int height = FindHeight(root);
    for(int i = 0; i <= height; i++){
        int width = countNodes(root, i);
        if(width > maxwidth){
            maxwidth = width;
        }
    }
    return maxwidth;
}
int main(){
    BstNode* root = GetNewNode(1);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        Insert(root, x, y, z);
    }
    cout << getMaxWidth(root) << endl;
    return 0;
}