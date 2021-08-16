#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dest;
};


struct Graph {

	int V, E;
	struct Edge* edge;
};

struct subset {
	int parent;
	int rank;
};


struct Graph* createGraph(int V, int E)
{
	struct Graph* graph
		= (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*)malloc(
		graph->E * sizeof(struct Edge));

	return graph;
}


int find(struct subset subsets[], int i)
{

	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int xroot, int yroot)
{

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int isCycle(struct Graph* graph)
{
	int V = graph->V;
	int E = graph->E;

	struct subset* subsets
		= (struct subset*)malloc(V * sizeof(struct subset));

	for (int v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for (int e = 0; e < E; ++e) {
		int x = find(subsets, graph->edge[e].src);
		int y = find(subsets, graph->edge[e].dest);

		if (x == y)
			return 1;

		Union(subsets, x, y);
	}
	return 0;
}


int main()
{
  int n,m1,m2,v,u;
  cin>>n>>m1>>m2;
	Graph * g1 = createGraph(n,m1);
  Graph * g2 = createGraph(n,m2);

  for(int i=0;i<m1;i++) {
    cin>>u>>v;
    u--;
    v--;
    g1->edge[i].src = u;
  	g1->edge[i].dest = v;
  }

  for(int i=0;i<m2;i++) {
    cin>>u>>v;
    u--;
    v--;
    g2->edge[i].src = u;
  	g2->edge[i].dest = v;
  }


	struct subset* subsets1 = (struct subset*)malloc(n * sizeof(struct subset));
  struct subset* subsets2 = (struct subset*)malloc(n * sizeof(struct subset));

	for (int v = 0; v < n; ++v) {
		subsets1[v].parent = v;
		subsets1[v].rank = 0;
    subsets2[v].parent = v;
		subsets2[v].rank = 0;
	}

  for (int e = 0; e < m1; ++e) {
        int x = find(subsets1, g1->edge[e].src);
        int y = find(subsets1, g1->edge[e].dest);
        Union(subsets1, x, y);
    }

    for (int e = 0; e < m2; ++e) {
          int x = find(subsets2, g2->edge[e].src);
          int y = find(subsets2, g2->edge[e].dest);
          Union(subsets2, x, y);
      }

  vector<pair<int,int>> ans;

  for(int u=0;u<n;u++){
    for(int v=u+1;v<n;v++){
      int x1 = find(subsets1, u);
      int y1 = find(subsets1, v);

      int x2 = find(subsets2, u);
      int y2 = find(subsets2, v);

      if (x1 != y1 && x2 != y2){
        ans.push_back({u,v});
        Union(subsets1, x1 , y1);
        Union(subsets2, x2 , y2);
      }

    }
  }
  int res = ans.size();
  cout<<res<<endl;
  for(int i=0;i<res;i++){
    cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
  }

	return 0;
}
