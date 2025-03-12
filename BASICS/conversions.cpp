//
//  conversion.cpp
//  STRIVERDSA
//
//  Created by MR KISHOR on 04/03/25.
//

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<stack>
using namespace std;

void inttoall(){
   int n;
   cin>>n;
   float a=static_cast<float>(n); // no points conversions here like 123.0
   cout<<a<<endl;
   double b=static_cast<double>(n); // no points conversions here like 123.0
   cout<<b<<endl;
   string c=to_string(n); // converts to string
   cout<<c<<endl;
}

void stringtoall(){
   string a;
   cin>>a;
   int num=stoi(a); // thread signalling of error handling due to incorrect approach
   cout<<num<<endl;
   float b=stof(a); // same here no points conversion here
   cout<<b<<endl;
   double d=stod(a); // same here no points conversion here
   cout<<d<<endl;
   
}

void floattoall(){
   float a;
   cin>>a;
   int b=static_cast<int>(a); // removes decimal values
   cout<<b<<endl;
   double c =static_cast<double>(a); // prints deci values
   cout<<c<<endl;
   string d= to_string(a); // prints all the possible dec values
   cout<<d<<endl;
}

void doubletoall(){

   double a;
   cin>>a;
   int b=static_cast<int>(a); // removes decimal values
   cout<<b<<endl;
   float c =static_cast<float>(a); // configures and ceils upto the 2 value after the .
   cout<<c<<endl;
   string d= to_string(a);  // prints all dec values
   cout<<d<<endl;
}
int main(){
//    inttoall();
//    stringtoall();
//    floattoall();
   doubletoall();
}
