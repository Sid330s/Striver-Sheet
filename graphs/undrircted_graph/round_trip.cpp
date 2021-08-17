#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> adj; // Adjecency List
void add_edge(int a, int b)
{
	adj[a].push_back(b);  //  Made it for Directed graph
  adj[b].push_back(a);
}


struct Ans
{
	bool flag;
  int dist;
  vector<int> path;
};

void DFS(int u,bool & res,vector<bool> &vis,vector<bool> &vis_dfs,int par,vector<int> &path,vector<int> & res_path){
    if(res) return;
    vis_dfs[u]=true;
    path.push_back(u);
    vis[u]=true;
    for(auto v:adj[u]){
        if(vis[v]){
            if(vis_dfs[v] && v!=par && !res){
              res=true;
              // cout<<"HI"<<endl;
              int i = path.size()-1;
              res_path.push_back(v);
              while(path[i]!=v) res_path.push_back(path[i]),i--;
              res_path.push_back(v);
              break;
            }
        }
        else{
            DFS(v,res,vis,vis_dfs,u,path,res_path);
        }
    }

    vis_dfs[u]=false;
    path.pop_back();

}

Ans isCycle()
{
    bool res = false;
    vector<bool> vis(n,false);
    vector<bool> vis_dfs(n,false);
    vector<int> path;
    vector<int> res_path;
    for(int u=0;u<n;u++){
        if(!vis[u]){
            DFS(u,res,vis,vis_dfs,-1,path,res_path);
            if(res)
              break;
        }
    }
   	return {res,(int)res_path.size(),res_path};
}


// { Driver Code Starts.
int main(){
  cin >> n >> e;
	adj.assign(n, vector<int>());
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
    a--;
    b--;
		add_edge(a, b);
	}
  Ans ans = isCycle();
  if(!ans.flag) cout<<"IMPOSSIBLE"<<endl;
  else{
    //reverse(ans.path.begin(),ans.path.end());
    cout<<ans.dist<<endl;
    for(auto u:ans.path) cout<<u+1<<" ";
    cout<<endl;
  }
	return 0;
}  // } Driver Code Ends
