#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>* adj;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void connectedComponents();
};

unordered_map<int,int> ump Graph::connectedComponents()
{
  unordered_map<int,int> ump;
	bool* visited = new bool[V];
	for (int v = 0; v < V; v++)
		visited[v] = false;

  int k=0;
	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			DFSUtil(v, visited,ump,k);
      k++;
			cout << "\n";
		}
	}
	delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[],unordered_map<int,int> &ump,int k)
{

	visited[v] = true;
	cout << v << " ";
  ump[v]=k;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited,ump,k);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int main()
{
  int n,m1,m2,v,u;
  cin>>n;
	Graph g1(n);
  Graph g2(n);
  for(int i=0;i<m1;i++) {
    cin>>u>>v;
    u--;
    v--;
    g1.addEdge(u, v);
  }
  for(int i=0;i<m2;i++) {
    cin>>u>>v;
    u--;
    v--;
    g2.addEdge(u, v);
  }

  unordered_map<int,int> ump1 = g1.connectedComponents();
  unordered_map<int,int> ump2 = g2.connectedComponents();

  for(int u=0;u<n;u++){
    for(int v=u+1;v<n;v++){
       if( ump1[u]==ump1[v] && )
    }
  }

	return 0;
}
