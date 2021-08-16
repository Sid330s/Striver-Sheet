#include<bits/stdc++.h>
using namespace std;
int n,a,b,t,k;
double res,cnt1,cnt0;
string s;
int arr[100005];
int main(){
    cin>>t;
    while(t--){
      cin>>s;
      n=s.length();
      arr[0]=0;
      for(int i=1;i<=n;i++) arr[i]=arr[i-1]+(s[i-1]-'0');
      // for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
      // cout<<endl;
      k=1;
      res=0;
      cnt1=0;
      cnt0=0;
      while(k*(k+1)<=n){
        for(int i=1,j=i+k*(k+1)-1;j<=n;i++,j++){
          cnt1 = (arr[j]-arr[i-1]);
          cnt0 = k*(k+1) - cnt1;
          if(cnt1*cnt1==cnt0){
            // cout<<i<<" "<<j<<endl;
            res++;
          }
        }
        k++;
      }
      cout << res<<endl;
    }
    return 0;
}
