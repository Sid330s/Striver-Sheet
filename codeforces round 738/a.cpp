#include<bits/stdc++.h>
using namespace std;
long long int arr[100005],n,t,res;
int main(){
    cin>>t;
    while(t--){
      cin>>n;
      for(int i=0;i<n;i++) cin>>arr[i];
      res=arr[0];
      for(int i=1;i<n;i++) res=res&arr[i];
      cout<<res<<endl;
    }
    return 0;
}
