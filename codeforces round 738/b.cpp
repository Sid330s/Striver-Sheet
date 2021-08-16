#include<bits/stdc++.h>
using namespace std;
long long int n,t,res;
string s;
int main(){
    cin>>t;
    while(t--){
      cin>>n;
      cin>>s;
      int i=0;
      while(i<n && s[i]=='?') i++;
      if(i==n){
          for(int p=0;p<n;p++) {
            if(p%2) s[p]='R';
            else s[p]='B';
          }
          cout<<s<<endl;
      }
      else{
        int j=i;
        i--;
        while(i>=0){
          if(s[i+1]=='R') s[i]='B';
          else s[i]='R';
          i--;
        }
        while(j<n){
          while(j<n && s[j]!='?') j++;
          while(j<n && s[j]=='?'){
            if(s[j-1]=='R') s[j]='B';
            else s[j]='R';
            j++;
          }
        }
        cout<<s<<endl;
      }

    }
    return 0;
}
