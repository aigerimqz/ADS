#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> steam, kteam;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            steam.push_back(i);
        } else {
            kteam.push_back(i);
        }
    }

    while (!steam.empty() && !kteam.empty()) {
        int s_student = steam.front();
        int k_student = kteam.front();
        steam.pop_front();
        kteam.pop_front();

        if (s_student < k_student) {
            steam.push_back(s_student + n);
        } else {
            kteam.push_back(k_student + n);
        }
    }

    if (steam.empty()) {
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }

    return 0;
}
