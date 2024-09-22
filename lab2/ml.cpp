#include <Iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }
    int curr = arr[0];
    int maxSub = arr[0];
    for(int i = 1; i < n; i++){
        maxSub = max(maxSub + arr[i], arr[i]);
        curr = max(curr, maxSub);
    }
    cout << curr;

    return 0;
}