#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack <char> st;
    for(int i = 0; i < s.length();i++){
        if(s[i] != st.top()){
            st.push(s[i]);
            
        }else{
            st.pop();
        }
    
    
    if(st.size() == 0){
        cout << "yes";
    }else{
        cout << "no";
    }
    return 0;
}