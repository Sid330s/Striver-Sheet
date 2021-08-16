#include<bits/stdc++.h>
using namespace std;
int n,k,res,ans;
string m[1005];
void dfs(int i,int j,vector<vector<int>> &vis){
  for()
}
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>m[i];
  vector<vector<int>> vis( n , vector<int> (m, 0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) {
       dfs(i,j,vis);
    }
  }
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
