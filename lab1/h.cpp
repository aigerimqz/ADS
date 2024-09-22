#include <iostream>
using namespace std;
void isPrime(int num){
    int cnt = 0;
    for(int i = 1; i < num + 1; i++){
        if (num % i == 0){
            cnt++;
        }
    }
    if(cnt == 2){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
int main(){
    int n; 
    cin >> n;
    isPrime(n);

    return 0;
}