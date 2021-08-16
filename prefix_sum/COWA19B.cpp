#include<bits/stdc++.h>
using namespace std;
int arr[1000005],brr[1000005],n,q,l,r,idx,m;
int main(){
  cin>>n;
  cin>>q;
  while(q--){
    cin>>l>>r;
    arr[l]+=1-l;
    arr[r+1]+=l-1;
    brr[l]+=1;
    brr[r+1]+=-1;
  }
  for(int i=1;i<=n;i++) brr[i]+=brr[i-1];
  for(int i=1;i<=n;i++) arr[i]+=arr[i-1];
  for(int i=1;i<=n;i++) arr[i]+=brr[i]*(i);
  cin>>m;
  while(m--){
    cin>>idx;
    cout<<arr[idx]<<endl;
  }
  return 0;
}
