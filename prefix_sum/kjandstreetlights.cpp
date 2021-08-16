#include<bits/stdc++.h>
using namespace std;
int x[200005],n,p,x_c,r_g,l,r,ans,f_ans;

int main(){

  cin>>n>>p;
  for(int i=0;i<=p;i++) x[i]=0;
  while(n--){
    cin>>x_c>>r_g;
    l=max(0,x_c-r_g);
    r=min(x_c+r_g,p);
    x[l]+=1;
    x[r+1]+=-1;
  }

  for(int i=1;i<=p;i++) x[i]=x[i]+x[i-1];

  // for(int i=0;i<=p;i++) cout<<x[i]<<" ";
  // cout<<endl;

  f_ans=0;
  for(int i=0;i<=p;i++) {
    ans=0;
    while(i<=p && x[i]!=1) ans++,i++;
    f_ans=max(f_ans,ans);
  }

  cout<<f_ans<<endl;
  return 0;
}
