#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int count1 = upper_bound(arr.begin(), arr.end(), r1) - lower_bound(arr.begin(), arr.end(), l1);
        int count2 = upper_bound(arr.begin(), arr.end(), r2) - lower_bound(arr.begin(), arr.end(), l2);
        
       
        int overlapCount = 0;
        if (l1 <= r2 && l2 <= r1) {
            overlapCount = upper_bound(arr.begin(), arr.end(), min(r1, r2)) - lower_bound(arr.begin(), arr.end(), max(l1, l2));
        }

        cout << count1 + count2 - overlapCount << endl;
    }

    return 0;
}