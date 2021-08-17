#include<bits/stdc++.h>
using namespace std;
#define INF 1e17

int n,e;

struct Edge{
    int u;
    int v;
    long long int w;
};

vector<Edge> edges;

void add_edge(int a, int b, long long int w)
{
	edges.push_back({a,b,w});  //  Made it for Directed graph
}

int main() {


    cin>>n>>e;
    int a, b;
    long long int w;

    vector<long long int> dist(n);
    vector<int> par(n, -1);

    for (int i = 0; i < e; i++) {
      cin >> a >> b >> w;
      a--;
      b--;
      add_edge(a, b, w);
    }

    // cout<<"Hi"<<endl;
    // dist[0]=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<e;j++){
          long long int value =dist[edges[j].u] + edges[j].w;
          if(dist[edges[j].u]== INF) value = INF;
          if(value < dist[edges[j].v] ){
            dist[edges[j].v]=value;
            par[edges[j].v]=edges[j].u;
          }

      }


    // for(int i=0; i<n; i++) cout<<dist[i]<<" ";
    // cout<<endl;


    int C = -1;
    for(int j=0;j<e;j++){
      long long int value =dist[edges[j].u] + edges[j].w;
      if(dist[edges[j].u]== INF) value = INF;
        if( value < dist[edges[j].v] ){
          C=edges[j].v;
          break;
        }
     }

    // cout<<"->"<<C<<endl;

    if (C != -1) {

        for (int i = 0; i < n; i++)
        C = par[C];


        // To store the cycle vertex
        vector<int> cycle;
        for (int v = C;; v = par[v]) {

            cycle.push_back(v);
            if (v == C
                && cycle.size() > 1)
                break;
        }

        // Reverse cycle[]
        reverse(cycle.begin(), cycle.end());

        // Printing the negative cycle
        cout << "YES" << endl;
        for (int v : cycle)
            cout << v+1 << ' ';
        cout << endl;
    }
    else
        cout << "NO" << endl;

     // if(!flag) cout<<"NO"<<endl;
     // else {
     //   cout<<"YES"<<endl;
     //   vector<int> path;
     //   int temp  = u;
     //   path.push_back(u);
     //   u=par[u];
     //   while(u!=-1 && u!=temp) path.push_back(u),u=par[u];
     //   path.push_back(temp);
     //   reverse(path.begin(),path.end());
     //   for(auto u:path) cout<<u+1<<" ";
     //   cout<<endl;
     // }

    return 0;
	}
