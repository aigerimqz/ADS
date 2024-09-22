#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    vector <int> check;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        v.push_back(value);
    }
    int k;
    cin >> k;
    for(int i = 0; i < n; i++){
        int a;
        a = v[i] - k;
        check.push_back(abs(a));
    } 
    int f, res = 0;
    f = check[0];
    for(int i = 1; i < n; i++){
        if(f > check[i]){
            f = check[i];
            res = i;
        }
    }
    cout << res;
    
    return 0;
}