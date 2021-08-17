#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> adj; // Adjecency List
void add_edge(int a, int b)
{
	adj[a].push_back(b);  //  Made it for Directed graph
}

struct Ans
{
	bool flag;
  int dist;
  vector<int> path;
};

void DFS(int u,bool & res,vector<bool> &vis,vector<bool> &vis_dfs){
    if(res) return;
    vis_dfs[u]=true;
    vis[u]=true;
    for(auto v:adj[u]){
        if(vis[v]){
            if(vis_dfs[v] && !res){
              res=true;
              break;
            }
        }
        else{
            DFS(v,res,vis,vis_dfs);
        }
    }
    vis_dfs[u]=false;
}

void DFS2(int u, vector<bool> &vis ,vector<int>&path){
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]){
            DFS2(v,vis,path);
        }
    }
    path.push_back(u);
}

vector<int> topoSort() {
    vector<bool> vis(n,false);
    vector<int> path;
    for(int u=0;u<n;u++)
        if(!vis[u])
          DFS2(u,vis,path);

    reverse(path.begin(),path.end());
    return path;
}

bool isCycle()
{
    bool res = false;
    vector<bool> vis(n,false);
    vector<bool> vis_dfs(n,false);
    for(int u=0;u<n;u++){
        if(!vis[u]){
            DFS(u,res,vis,vis_dfs);
            if(res)
              break;
        }
    }
   	return res;
}

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
  bool flag = isCycle();
  if(flag) cout<<"IMPOSSIBLE"<<endl;
  else{
    vector<int> path = topoSort();
    for(auto u:path) cout<<u+1<<" ";
    cout<<endl;
  }
	return 0;
}
// } Driver Code Ends
