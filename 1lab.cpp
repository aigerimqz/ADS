#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, value = 0;
    vector <int> v;
    vector <int> v1;
    vector <int> res;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        v.push_back(value);
        v1.push_back(value);
    }
    for(int i = 0; i < n; i++){
        int val = 0;
        for(int j = 1; j < n - 1; j++){
            if (v[i] < v1[j]){
                res.push_back(val);
            }
            else if(v[i] > v1[j]){
                val == 0;
            }
        }
    }
    return 0;
}