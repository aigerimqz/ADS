#include <iostream>
#include <deque>
using namespace std;

int main(){
    char sign, operation;
    int num, res;
    deque <int> d;
    deque <string> result;
    
    while(sign != '!'){
        cin >> sign;

        if(sign == '+'){
            cin >> num;
            d.push_front(num);
        }else if(sign == '-'){
            cin >> num;
            d.push_back(num);
        }else if(sign == '*'){
            if(d.size() == 0){
                result.push_back("error");
            }
            else if(d.size() == 1){
                string ress;
                ress = to_string(d.front() + d.back());
                result.push_back(ress);
                d.pop_back();
            }
            else{
                string ress;
                res = d.front() + d.back();
                ress = to_string(res);
                result.push_back(ress);
                d.pop_front();
                d.pop_back();
            }
            

        }

    }
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}