#include<iostream>
using namespace std;
int main(){
    int a[] = {1,2,3,4,1}; 
    int b=static_cast<int>(*a);
    cout<<b<<endl;
    // cout<<&a+1.to_integer()<<endl; // Single integer variable
    // int *b;      // Pointer variable
    // b = &a;      // b points to address of a
    return 0;
}