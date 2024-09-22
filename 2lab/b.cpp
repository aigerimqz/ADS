#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector <string> v;
    vector <string> v1;
    for(int i = 0; i < n; i++){
        string value;
        cin >> value;
        v.push_back(value);
    }
    for(int i = k; i < n; i++){
        v1.push_back(v[i]);
    }
    for(int i = 0; i < k; i++){
        v1.push_back(v[i]);
    }
    for(int i = 0; i < n; i++){
        cout << v1[i] << " ";
    }
    return 0;
}