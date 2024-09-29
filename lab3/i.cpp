#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int x){
    int left, right, mid;
    left = 0;
    right = n - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;

}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }
    int x;
    cin >> x;
    if(BinarySearch(arr, n, x) != -1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}