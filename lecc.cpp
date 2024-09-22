#include <iostream>
using namespace std;


//binary search -------------------------------------------------------------------------------------------

// int bin_search(int* arr, int beg, int end, int key){
//     //stopping conditions
//     int mid = (beg + end)/2;
//     if(arr[mid] == key){
//         return mid;
//     }
//     if(beg == end){
//         cout << "not found";
//         return INT_MAX;
//     }
//     //recursion invokation
//     if(key < arr[mid])
//         return bin_search(arr, beg, mid-1, key);
//     else
//         return bin_search(arr, mid + 1, end, key);
    
// }

// int main(){
//     int arr[7] = {1,2,3,5,6,8,9};
//     cout << bin_search(arr, 0, 6, 3) << endl;
//     return 0;
// }

//-----------------------------------------------------------------------------


int bin_search(int* arr, int beg, int end, int key){
    //stopping conditions
    int mid = (beg + end)/2; //C1
    if(arr[mid] == key){ //C2
        return mid; //C3
    }
    if(beg == end){ //C4
        cout << "not found"; //C5
        return INT_MAX; //C6
    }
    //recursion invokation
    if(key < arr[mid]) //C7
        return bin_search(arr, beg, mid-1, key); //C8
    else
        return bin_search(arr, mid + 1, end, key); //C9
    
}

int main(){
    int arr[7] = {1,2,3,5,6,8,9};
    cout << bin_search(arr, 0, 6, 3) << endl;
    return 0;
}

