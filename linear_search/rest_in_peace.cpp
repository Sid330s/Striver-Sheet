#include<bits/stdc++.h>
using namespace std;
long long int t,n,m;
string s;
bool ans;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    ans=true;
    if(n%21==0)
      ans=false;
    s=to_string(n);
	m=s.length();
	for(int i=0;i<m-1;i++)
		if(s[i]=='2' && s[i+1]=='1'){
			ans=false;
			break;
		}


    if(ans)
      cout<<"The streak lives still in our heart!"<<endl;
    else
      cout<<"The streak is broken!"<<endl;

  }
  return 0;
}
