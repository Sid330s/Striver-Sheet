#include<bits/stdc++.h>
using namespace std;

map<char,int> ump;
string s;
int n;

int main(){
  getline(cin, s);
  n = s.length();
  for(int i=0;i<n;i++)
    ump[s[i]]=0;

  for(int i=0;i<n;i++)
    ump[s[i]]++;

  int max_freq = 0;
  char freq_ele;
  for(auto e : ump){
      if(e.second>max_freq){
        max_freq=e.second;
        freq_ele = e.first;
      }
  }

  cout<<freq_ele<<" "<<max_freq<<endl;
  return 0;
}
