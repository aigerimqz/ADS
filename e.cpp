#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i = 0, val1, val2;
    vector <int> v1, v2;
    for (int i = 0; i < 5; i++){
        cin >> val1;
        v1.push_back(val1);
    }
    for (int i = 0; i < 5; i++){
        cin >> val2;
        v2.push_back(val2);
    }
    int n = 0;
    
    while((v1.size() != 0) && (v2.size() != 0)){
        
        if ((v1[i] == 0 && v2[i] == 9) || ((v1[i] > v2[i]) && !(v1[i] == 9 && v2[i] == 0))){
            
            v1.push_back(v1[i]);
            v1.push_back(v2[i]);
    
        }else{

            v2.push_back(v1[i]);
            v2.push_back(v2[i]);
        }
        v1.erase(v1.begin());
        v2.erase(v2.begin());
        n++;
    }
    if(v1.size() == 0){
        cout << "Nursik" << " " << n;
    }
    else if(v2.size() == 0){
        cout << "Boris" << " " << n;
    }else{
        cout << "blin nichya";
    }

    
 

    return 0;
}