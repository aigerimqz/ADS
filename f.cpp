#include <iostream>
using namespace std;
int isPrime(int num){
    int cnt  = 0, res = 0;
    for (int i = 1; i < num + 1; i++){
        if(num % i == 0){
            cnt++;
        }
    }
    if (cnt == 2){
        res = 1;
    }
    return res;
}
int main(){
    int n, c = 0, r = 0, i = 1;
    cin >> n;
    while(c != n){
        if (isPrime(i)){
            c++;
            if (c == n){
                r = i;
            }
        }
        i++;

    }
    cout << r;
    
    return 0;
}