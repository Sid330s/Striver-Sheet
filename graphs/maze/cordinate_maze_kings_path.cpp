#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};


int main(){
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	long long int r,a,b;
  map<pair<long long int,long long int>,int>m;
  queue<pair<long long int,long long int>> q;
	while(n--){
		cin>>r>>a>>b;
		for(int i=a;i<=b;i++) m[{r,i}]=-1;
	}
	m[{x1,y1}]=0;
	q.push({x1,y1});
	while(q.size()){
		pair<long long int,long long int> u=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			pair<long long int,long long int> v = {u.first+dx[i],u.second+dy[i]};
			if(m.count(v) && m[v]==-1) m[v]=m[u]+1,q.push(v);
		}
	}
	cout<<m[{x2,y2}]<<endl;
return 0;
}
