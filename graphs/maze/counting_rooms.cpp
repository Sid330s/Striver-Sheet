#include<bits/stdc++.h>
using namespace std;
int n,m,k,res,ans;
string mat[1005];

bool isSafe(int i,int j,vector<vector<bool>> &vis){
    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]|| mat[i][j]=='#') return false;
    return true;
}

void dfs(int i,int j,vector<vector<bool>> &vis){
  int dx[4]={1,0,0,-1};
  int dy[4]={0,-1,1,0};
  vis[i][j]=true;
  for(int k=0;k<4;k++){
      if(isSafe(i+dx[k],j+dy[k],vis)){
          dfs(i+dx[k],j+dy[k],vis);
      }
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>mat[i];
  vector<vector<bool>> vis( n , vector<bool> (m, 0));
  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) {
       if(isSafe(i,j,vis)){
         dfs(i,j,vis);
         cnt++;
       }
    }
  }

  cout<<cnt<<endl;
  return 0;
}
