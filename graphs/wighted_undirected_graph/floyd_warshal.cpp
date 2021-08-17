#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000000
int n, e, q;
vector<vector<long long int>> mat;


void add_edge(int a, int b, long long int c)
{
  mat[a][b]=min(mat[a][b],c);
  mat[b][a]=min(mat[b][a],c);
}

void floydWarshall()
{
	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (int j = 0; j < n; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// mat[i][j]
			  mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
			}
		}
	}
}

// Driver code
int main()
{
	/* Let us create the following weighted graph
			10
	(0)------->(3)
		|	 /|\
	5 |	 |
		|	 | 1
	\|/	 |
	(1)------->(2)
			3	 */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e >> q;
  	mat.assign(n, vector<long long int>( n , INF ));
    for(int i=0;i<n;i++) mat[i][i]=0;
  	int a, b;
    long long int w;
  	for (int i = 0; i < e; i++) {
  		cin >> a >> b >> w;
      a--;
      b--;
  		add_edge(a, b, w);
  	}
    floydWarshall();
    while(q--){
      cin >> a >> b;
      a--;
      b--;
      if(mat[a][b]==INF) cout<<-1<<endl;
      else cout<<mat[a][b]<<endl;
    }
    return 0;
}

// This code is contributed by Mythri J L
