#include <iostream>
using namespace std;



int main(){
    int t, n, m;
    cin >> t;
    int arr[t];
    for(int i = 0; i < t; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }
    cin >> n >> m;
    int arr2[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            arr2[i][j] = val;
        }
    }
    for(int i = 0; i < t; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arr[i] == arr2[j][k]){
                    cout << j << " " << k << endl;
                    break;
                    
                }
                else if(j == (n - 1) && k == (m - 1) && arr[i] != arr2[j][k]){
                    cout << -1 << endl;
                }
            }
        }
    }

 
    return 0;
}