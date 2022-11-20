#include<iostream>
using namespace std;
int main(){
      int n;
      int x=1;
      cin>>n;
      while (n/x>9)
      {
        x*=10;
      }
      while (x>=0)
      {
        cout<<"\n"<<n/x;
        x/=10;
      }
      return 0;
}