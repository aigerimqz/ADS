#include <iostream>
using namespace std;
int main(){
    int n, p;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }
    cin >> p;
    for(int i = 0; i < p; i++){
        int power, kill = 0, sum = 0;
        cin >> power;
        for(int j = 0; j < n; j++){
            if(power >= arr[j]){
                kill++;
                sum += arr[j];
            }
        }
        cout << kill << " " << sum << endl;
    }
    return 0;
}