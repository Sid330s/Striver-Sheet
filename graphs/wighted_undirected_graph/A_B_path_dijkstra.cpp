#include<bits/stdc++.h>
using namespace std;
#define INF 100000000000000000
int n, e;
vector<vector<pair<long long int,int>>> adj;

struct Ans
{
	bool flag;
  int dist;
  vector<int> path;
};

void add_edge(int a, int b, long long int w)
{
	adj[a].push_back({w,b});
  adj[b].push_back({w,a});  //  Made it for Directed graph
}

Ans path_dijkstra(int src)
{
    // Code here
    vector<long long int> dist(n, INF);
    vector<int> par(n, -1);
    vector<bool> vis(n,false); // vistied track
    priority_queue<pair<long long int, int>, vector <pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
				long long int w = pq.top().first;
        pq.pop();
				if(vis[u]) continue;
				vis[u]=true;
        for (auto x : adj[u])
        {
            int v = x.second;
            int weight = x.first;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                par[v]=u;
            }
        }
    }

    vector<int> path;
    int u = n-1;
    while(u!=-1) path.push_back(u),u=par[u];
    return {dist[n-1]!=INF,(int)path.size(),path};
}





int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> e;
	adj.assign(n, vector<pair<long long int,int>>());
	int a, b;
  long long int w;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
    a--;
    b--;
		add_edge(a, b, w);
	}
  Ans ans = path_dijkstra(0);
  if(!ans.flag) cout<<"-1"<<endl;
  else{
    reverse(ans.path.begin(),ans.path.end());
    for(auto u:ans.path) cout<<u+1<<" ";
    cout<<endl;
  }
  return 0;
}

/*
10 10
1 5 12
2 4 140
2 10 149
3 6 154
3 7 9
3 8 226
3 10 132
4 10 55
5 8 33
7 8 173

*/
