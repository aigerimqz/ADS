#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, val = 0;
    cin >> n;
    vector <int> v;
    vector <int> res;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        v.push_back(value);
        res.push_back(-1);
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] >= v[j]){
                res[i] = v[j];
                break;
                
            }
         
        }
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
    return 0;
}