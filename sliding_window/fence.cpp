#include<bits/stdc++.h>
using namespace std;
long long int arr[200005],n,k,res,ans;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) arr[i]=arr[i]+arr[i-1];
    res=1000000000;
    for(int i=1,j=k;j<=n;i++,j++){
      if( res > (arr[j]-arr[i-1]) ){
        res=(arr[j]-arr[i-1]);
        ans=i;
      }
    }
    cout<<ans<<endl;
    return 0;
}
