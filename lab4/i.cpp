#include <iostream>
using namespace std;
struct Node {

	int data;
    int cnt;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
        this->cnt = 1;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} 
    else if(root->data == data){
        root->cnt++;
    }
    else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
        root->cnt--;
        if(root->cnt == 0){
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->cnt = temp->cnt;
                temp->cnt = 1;
                root->right = deleteNode(root->right, temp->data);
                
            }
        }    
	}
    return root;
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int count(Node* root, int x){
    Node* node = find(root, x);
    if(node){
        return node->cnt;
    }
    return 0;
}

void getQuery(Node*& root, string query, int value){
    if(query == "insert"){
        root = add(root, value);
    }
    else if(query == "delete"){
        root = deleteNode(root, value);
    }
    else if(query == "cnt"){
        cout << count(root, value) << endl;
    }
}

int main(){
    Node* root = NULL;

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        int val;
        cin >> s >> val;
        getQuery(root, s, val);

    }
    return 0;
}