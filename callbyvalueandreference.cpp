#include<bits/stdc++.h>
using namespace std;

int tripleByValue(int num){
  return num*3; 
}
int tripleByReference(int& num){
  num = num*3;
}
int main(){
  int num;
  cin>>num;
  int newvalue = num;
  cout<<"new value of input nummber triple from call by value is \t"<<tripleByValue(num)<<endl;
  cout<<"\n";
  tripleByReference(newvalue);
  cout<<"new value of input nummber triple from call by reference is\t"<<newvalue<<endl;
}