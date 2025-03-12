//
//  Basicmath.cpp
//  STRIVERDSA
//
//  Created by MR KISHOR on 04/03/25.
//
// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

using namespace std;

void countdigit(){
  int count=0;
  int n;
  cout<<endl;
  cin>>n;
  while(n!=0){
     int ld=n%10;
      cout<<ld<<" ";
      count++;
      n/=10;
  }
}
void reversedigit(){
  int count=0;
  int n;
  cin>>n;
  int rd=0;
  int len = static_cast<int>(to_string(n).length());
  while(n!=0){
     int ld=n%10;
      rd+=ld*pow(10, len-count-1);
      cout<<ld<<" ";
      count++;
      n/=10;
  }
  cout<<endl;
  cout<<rd;
}

void palindromee(){
  int n;
  cin>>n;
  int orignal=n;
  int rd=0;
  while(n!=0){
      int ld=n%10;
      rd = rd * 10 + ld;
      n/=10;
  }
  if(rd==orignal){
      cout<<"Palindrome"<<endl;
  }
  else{
      cout<<"Not Palindrome"<<endl;
  }
}

void armstrongnum(){
  int a;
  cin>>a;
  int original=a;
  int ts=0;
  int digits = static_cast<int>(to_string(a).length());
  while(a!=0){
      int ld=a%10;
      ts+=pow(ld,digits);
      a/=10;
  }
  cout<<((original==ts)?"Armstrong Number":"Not Armstrong Number");
  cout<<endl;
//    if(ts==original){
//        cout<<"Armstrong Number";
//    }
//    else{
//
//    }
}
int main(){
//    countdigit();
//    reversedigit();
//    palindromee();
  armstrongnum();
}
