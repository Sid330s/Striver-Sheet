#include<bits/stdc++.h>
using namespace std;
long long int t,n,cnt;
string s;
bool ans;

int main(){
  cin>>t;
  while(t--){
    cin>>s;
    n=s.length();
    cnt=0;
    int i=0;
    ans=true;
    while(i<n && s[i]=='0') i++;
    if(i==n)
      ans=false;
    while(i<n && s[i]=='1') i++;
    while(i<n && s[i]=='0') i++;
    while(i<n)
      if(s[i]=='1'){
        ans=false;
        break;
      }

    if(ans)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }
  return 0;
}
