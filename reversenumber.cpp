#include <bits/stdc++.h>
using namespace std;

int reverse(int val){
  int ans=0;
  while(val>0){
    ans=val%10+ans*10;
    val=val/10;
  }
  cout<< ans;
}
int main(){
  int val;
  cin>>val;
  return reverse(val);
}