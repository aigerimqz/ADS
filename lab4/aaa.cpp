#include <iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
BstNode* Insert(BstNode* root, int data){
    if(root == nullptr){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else if(data > root->data){
        root->right = Insert(root->right, data);
    }
    return root;
}

bool checkExisting(BstNode* root, string path){
    BstNode* current = root;

    for(int i = 0; i < path.size(); i++){
        if(path[i] == 'L'){
            if(current->left){
                current = current->left;
            }else{
                return false;
            }
        }
        else if(path[i] == 'R'){
            if(current->right){
                current = current->right;
            }else{
                return false;
            }

        }
    }
    return true;
}


int main(){
    BstNode* root = nullptr;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = Insert(root, val); 
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(checkExisting(root, s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}