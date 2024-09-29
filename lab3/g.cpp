#include <iostream>
using namespace std;
int check(int arr[], int n, int c){
    int f = 0;
    for (int i = 0; i < n; i++){
        f += (arr[i] + c - 1)/c;
    }
    return f;
}

int main(){
    int n, f;
    cin >> n >> f;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxi = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] >= maxi){
            maxi = arr[i];
        }
    }
    int left = 1, right = maxi, res = right;
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(arr, n, mid) <= f){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << res << endl;
    

    return 0;
}