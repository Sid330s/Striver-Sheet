#include<bits/stdc++.h>
using namespace std;
#define INF 1e18

int n,e;

struct Edge{
    int u;
    int v;
    long long int w;
};

vector<Edge> edges;

void add_edge(int a, int b, long long int w)
{
	edges.push_back({a,b,-w});  //  Made it for Directed graph
}

int main() {


    cin>>n>>e;
    int a, b;
    long long int w;

    vector<long long int> dist(n, INF);

    for (int i = 0; i < e; i++) {
      cin >> a >> b >> w;
      a--;
      b--;
      add_edge(a, b, w);
    }

    dist[0]=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<e;j++){
          long long int value =dist[edges[j].u] + edges[j].w;
          if(dist[edges[j].u]== INF) value = INF;
          if(value < dist[edges[j].v] )
              dist[edges[j].v]=value;
        }


    // for(int i=0; i<n; i++) cout<<dist[i]<<" ";
    // cout<<endl;

    bool flag = false;
    for(int i=0;i<n-1;i++)
       for(int j=0;j<e;j++){
          long long int value =dist[edges[j].u] + edges[j].w;
          if(dist[edges[j].u]== INF) value = INF;
           if( value < dist[edges[j].v] ) dist[edges[j].v]=-INF;
     }

     // for(int i=0; i<n; i++) cout<<dist[i]<<" ";
     // cout<<endl;

    if(dist[n-1]==-INF) cout<<"-1"<<endl;
    else cout<<dist[n-1]*(-1)<<endl;
    return 0;
	}
