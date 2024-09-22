# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
	Node* temp = head;
    int curr = head->val;
    int maxsum = head->val;
    Node* aftercurr = head->next;
    while(aftercurr != nullptr){
        
        curr = max(curr + aftercurr->val, aftercurr->val);
        maxsum = max(maxsum, curr);
        aftercurr = aftercurr->next;
    }
    return maxsum;

}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
