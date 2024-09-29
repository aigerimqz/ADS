#include <iostream>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;

    int arr[n];
    int res[q];
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }

    for(int i = 0; i < q; i++){
        int l1, r1, l2, r2, cnt = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        for(int j = 0; j < n; j++){
            if(((l1 <= arr[j]) && (arr[j] <= r1)) || ((l2 <= arr[j]) && (arr[j] <= r2))){
                cnt++;
            }
        }
        res[i] = cnt;
    }
    for(int i = 0; i < q; i++){
        cout << res[i] << endl;
    }

    return 0;
}