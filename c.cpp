#include <iostream>
#include <vector>
using namespace std;
int main(){
    int numb = 0, numb2 = 0, cnt  = 1;
    string a, b;
    string a1 = "";
    string b1 = "";
    vector <char> v;
    cin >> a >> b;

    a1.push_back(a[0]);
    b1.push_back(b[0]);
    for (int i = 1; i < a.length(); i++){
        if (a[i] == '#'){
            a1.pop_back();
        }else{
            a1.push_back(a[i]);
        }  
    }
    for (int i = 1; i < b.length(); i++){
        if (b[i] == '#'){
            b1.pop_back();
        }else{
            b1.push_back(b[i]);
        }
    }
 
    if(a1 == b1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    
    return 0;
}