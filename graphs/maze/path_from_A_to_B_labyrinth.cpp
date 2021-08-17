#include<bits/stdc++.h>
using namespace std;
int n,m,k,res,ans;
string mat[1005];

struct Point
{
	int x;
	int y;
  int k;
};

Point par[1005][1005];

struct queueNode
{
	Point pt;
	int dist; //parent
};

struct Ans
{
	bool flag;
  int dist;
  string path;
};


char step(int k){
    if(k==0) return 'D';
    else if(k==1) return 'L';
    else if(k==2) return 'R';
    else if(k==3) return 'U';
    else return '\0';
}

bool isSafe(int i,int j,vector<vector<bool>> &vis){
    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]|| mat[i][j]=='#') return false;
    return true;
}


Ans BFS(Point src, Point dest)
{

  Ans ans = {false,-1,""};

  int dx[4]={1,0,0,-1};
  int dy[4]={0,-1,1,0};

	vector<vector<bool>> vis( n , vector<bool> (m, false));

	queue<queueNode> q;
	queueNode s = {src, 0};
  vis[src.x][src.y] = true;
  par[src.x][src.y] = {-1,-1,-1};
	q.push(s);

	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		if (pt.x == dest.x && pt.y == dest.y){
      ans.flag = true;
      ans.dist = curr.dist;
      while(! (pt.x==src.x && pt.y==src.y ) ) ans.path+=step(pt.k), pt = par[pt.x][pt.y];
      return ans;
    }

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + dx[i];
			int col = pt.y + dy[i];
			if (isSafe(row, col,vis))
			{
				vis[row][col] = true;
        par[row][col] = pt;
				queueNode Adjcell = { { row, col, i }, curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	return ans;
}



int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>mat[i];
  int cnt=0;
  Point src, dest;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) {
       if(mat[i][j]=='A') src.x = i , src.y = j, src.k = -1;
       if(mat[i][j]=='B') dest.x = i, dest.y = j, dest.k = -1;
    }
  }
  int dx[4]={1,0,0,-1};
  int dy[4]={0,-1,1,0};
  Ans ans = BFS(src,dest);
  if(!ans.flag) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    reverse(ans.path.begin(),ans.path.end());
    cout<<ans.dist<<endl;
    cout<<ans.path<<endl;
  }
  return 0;
}
