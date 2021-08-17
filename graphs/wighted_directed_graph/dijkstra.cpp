#include<bits/stdc++.h>
using namespace std;
#define INF 100000000000000000
int n, e;
vector<vector<pair<long long int,int>>> adj;

void add_edge(int a, int b, long long int w)
{
	adj[a].push_back({w,b});  //  Made it for Directed graph
}

vector <long long int> dijkstra(int src)
{
    // Code here
    vector<long long int> dist(n, INF);
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
            }
        }
    }
    return dist;
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
  vector<long long int> res = dijkstra(0);
  for(int i=0; i<n; i++) cout<<res[i]<<" ";
  cout<<endl;
  return 0;
}
