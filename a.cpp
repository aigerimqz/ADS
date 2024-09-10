#include <iostream>
#include <deque>
#include <vector>
using namespace std;
void Check(int item){
    deque <int> dq;
    for(int i = item; i > 0; i--){
        dq.push_front(i);
        for(int j = 0; j < i; j++){
            int b = dq.back();
            dq.pop_back();
            dq.push_front(b);
        }
    }
    for (int i = 0; i < dq.size(); i++){
        cout << dq[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    vector <int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        v.push_back(val);

    }
    for(int i = 0; i < v.size(); i++){
        Check(v[i]);
    }
    
    
    

    return 0;
}