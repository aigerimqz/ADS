#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        v.push_back(value);
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cout << v[i] << " ";
        }
    }
    return 0;
}