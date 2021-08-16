#include<bits/stdc++.h>
using namespace std;

map<string,int> ump;
string s;
int n,t;

int main(){
  cin>>t;
  while(t--){
    cin>>s;
    if(ump.find(s)==ump.end()){
      ump[s]=0;
      cout<<"OK"<<endl;
    }
    else {
      ump[s]++;
      cout<<s<<ump[s]<<endl;
    }
  }

  return 0;
}
