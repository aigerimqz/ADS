#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        deque<char> d;
        int count[26] = {0};

        for (int j = 0; j < m; j++) {
            char s;
            cin >> s;
            count[s - 'a']++;

            if (count[s - 'a'] == 1) {
                d.push_back(s);
            }

            while (!d.empty() && count[d.front() - 'a'] > 1) {
                d.pop_front();
            }

            if (d.empty()) {
                cout << -1 << " ";
            } else {
                cout << d.front() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
