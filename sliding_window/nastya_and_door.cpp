#include<bits/stdc++.h>
using namespace std;
long long int arr[200005],brr[200005],n,k,t,res,x,y;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    brr[1]=0;
    brr[n]=0;
    for(int i=2;i<=n-1;i++){
      if(arr[i-1]<arr[i] && arr[i+1]<arr[i]) brr[i]=brr[i-1]+1;
      else brr[i]=brr[i-1];
    }
    res=0;
    for(int i=1,j=i+k-1;j<=n;i++,j++){
      if(res < (brr[j-1]-brr[i])){
        res=(brr[j-1]-brr[i]);
        x=i;
        y=j;
      }
    }
    cout<<res+1<<" "<<x<<endl;
  }
    return 0;
}
