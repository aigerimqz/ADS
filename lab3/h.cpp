#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> c(n);
    c[0] = a[0];
    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int x = b[i];
        int idx = BinarySearch(c.data(), n, x);
        cout << idx + 1 << endl;
    }

    return 0;
}