#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> adj; // Adjecency List

struct queueNode
{
	int id;
	int dist; //parent
};

struct Ans
{
	bool flag;
  int dist;
  vector<int> path;
};


void add_edge(int a, int b)
{
	adj[a].push_back(b);  //  Made it for Directed graph
  adj[b].push_back(a);
}


Ans BFS(int src,int dest)
{
  Ans ans = {false,-1};
  vector<bool> vis(n,false); // vistied track


  unordered_map<int,int> par;

  queue<queueNode> q;  //queue
  queueNode s = {src, 0};
  vis[src] = true;
  par[src]=-1;
	q.push(s);

	while (!q.empty()) {
    queueNode curr = q.front();
		int u = curr.id;
		q.pop();

    if (u == dest){
      ans.flag = true;
      ans.dist = curr.dist;
      while( u!=-1 ) ans.path.push_back(u), u = par[u];
      return ans;
    }

		// Enqueue all adjacent of f and mark them vis
		for (auto v : adj[u]) {
			if (!vis[v]) {
				q.push({v,curr.dist + 1});
        vis[v] = true;
        par[v]=u;
			}
		}
	}

  return ans;
}

int main()
{

	cin >> n >> e;
	adj.assign(n, vector<int>());
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
    a--;
    b--;
		add_edge(a, b);
	}
  Ans ans = BFS(0,n-1);
  if(!ans.flag) cout<<"IMPOSSIBLE"<<endl;
  else{
    reverse(ans.path.begin(),ans.path.end());
    cout<<ans.dist+1<<endl;
    for(auto u:ans.path) cout<<u+1<<" ";
    cout<<endl;
  }

	return 0;
}
