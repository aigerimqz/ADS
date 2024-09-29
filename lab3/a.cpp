#include <iostream>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    cin >> n >> m;
    int arr2[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[i] == arr2[j][k]) {
                    cout << j << " " << k << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
