//
//  BasicRecursions.cpp
//  STRIVERDSA
//
//  Created by MR KISHOR on 05/03/25.
//

#include<iostream>
using namespace std;

void func(int count , int limit){
  if(count==limit){
      return;
  }
  cout<<"Kishor"<<"\n";
  func(count+1,limit);
//    cout<<"Kishor"<<"\n";
//    func(count+1,limit);
}

void printlinearly(int count,int range){
//    cout<<count<<endl;
  if(count==range){
      return;
  }
//    cout<<count<<endl; // prints from 0 to n-1
  printlinearly(count+1, range);
  cout<<count<<endl;  // prints from n-1 to 0
  
}
void recu(int n,int a){
  if(n<a){
      return;
  }
  recu(n-1,a);
  cout<<n<<endl;
  
}

void sumofn(int range,int sum){
  if(range<0){
      cout<<"The total sum is : "<<sum<<endl;
      return;
  }
  sumofn(range-1,sum+range);
}

int factorial(int n){
  if(n==0){
      return 1;
  }
  return n*factorial(n-1);
}

void reverseofanarray(){
  
  
}


int main(){
  int limit;
  cout << "Enter a positive number: ";
  cin>>limit;
  
  // Input validation
  if(limit < 0) {
      cout << "Please enter a positive number" << endl;
      return 1;
  }
  
  // Uncomment any one of these to test different functions
  // func(0, limit);
  // printlinearly(0, limit);
  // recu(limit, 0);
  // sumofn(limit, 0);
  cout << "Factorial of " << limit << " is: " << factorial(limit) << endl;
  
  return 0;
}
