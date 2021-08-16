#include<bits/stdc++.h>
using namespace std;
long long int arr[200005],n,k,t,res;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) arr[i+n]=arr[i];
    for(int i=1;i<=2*n;i++) arr[i]=arr[i]+arr[i-1];
    res=0;
    for(int i=1,j=i+k-1;i<=n;i++,j++) res=max(res,(arr[j]-arr[i-1]));
    cout<<res<<endl;
  }
    return 0;
}
