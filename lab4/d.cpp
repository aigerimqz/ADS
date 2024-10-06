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

    else{
        root->right = Insert(root->right, value);
    }
    return root;
}
BstNode* Search(BstNode* root, int x){
    if(root == nullptr || root->data == x){
        return root;
    }
    else if(x <= root->data){
        return Search(root->left, x);
    }
    else{
        return Search(root->right, x);
    }
}

int getLevel(BstNode* root){
    if(root == nullptr){
        return 0;
    }
    return max(getLevel(root->left), getLevel(root->right)) + 1;
}


void printLevel(BstNode* root, int level, int &levelSum){
    if(root == nullptr){
        return;
    }
    if(level == 0){
        levelSum += root->data;
    }else{
        printLevel(root->left, level - 1, levelSum);
        printLevel(root->right, level - 1, levelSum);
    }
}

void levelOrderSum(BstNode* root, int maxlevel){
    for(int level = 0; level < maxlevel; level++){
        int levelSum = 0;
        printLevel(root, level, levelSum);
        cout << levelSum << " ";
    }
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
    int maxlevel = getLevel(root);
    cout << maxlevel << endl;
    levelOrderSum(root, maxlevel);
    return 0;
}