#include <bits/stdc++.h>
using namespace std;
int n, e, m;
vector<vector<int>> adj; // Adjecency List
void add_edge(int a, int b)
{
	adj[a].push_back(b);  //  Made it for Directed graph
}

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

string words[1000];
int main(){
  cin>>m;
  for(int i=0;i<m;i++) cin>>words[i];

  n = 26;
	adj.assign(n, vector<int>());

  bool isLex = true;

  for (int i = 0; i < m-1; i++)
	{

		string word1 = words[i], word2 = words[i+1];
		for (int j = 0; j < min(word1.length(), word2.length()); j++)
		{
			if (word1[j] != word2[j])
			{
				add_edge(word1[j]-'a', word2[j]-'a');
				break;
			}
      else {
        if(j==min(word1.length(), word2.length())-1 && word1.length() > word2.length()) isLex = false;
      }
		}


	}

  bool flag = isCycle();
  if(flag || (! isLex )) cout<<"Impossible"<<endl;
  else{
    vector<int> path = topoSort();
    for(auto u:path) cout<<(char)(u+'a');
    cout<<endl;
  }
	return 0;
}
// } Driver Code Ends
