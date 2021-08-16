#include<bits/stdc++.h>
using namespace std;
long long int arr[100005],n,a,b,t;
double res,term;
int main(){
    cin>>t;
    while(t--){
      cin>>n>>b>>a;
      for(int i=1;i<=n;i++) cin>>arr[i];
      for(int i=1;i<=n;i++) arr[i]+=arr[i-1];
      int k=a;
      res=0;
      while(k<=b){
        for(int i=1,j=i+k-1;j<=n;i++,j++){
          term= (double)(arr[j]-arr[i-1])/(j-i+1);
          res=max(res,term);
        }
        k++;

      }
      cout << fixed << setprecision(7) << res<<endl;
    }
    return 0;
}
