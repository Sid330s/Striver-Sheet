#include<bits/stdc++.h>
using namespace std;
int arr[100005],n,t;
bool flag;
int main(){
    cin>>t;
    while(t--){
      cin>>n;
      for(int i=0;i<n;i++) cin>>arr[i];
      if(arr[n-1]==0){
          for(int p=1;p<=n+1;p++) cout<<p<<" ";
          cout<<endl;
      }
      else if(arr[0]==1){
          cout<<n+1<<" ";
          for(int p=1;p<=n;p++) cout<<p<<" ";
          cout<<endl;
      }
      else{
        flag=false;
        int i=0,j=1;
        while(j<n){
          if(arr[i]==0 && arr[j]==1){
            flag=true;
            break;
          }
          i++;
          j++;
        }
        i++;
        j++;

        if(flag){
          for(int p=1;p<=i;p++) cout<<p<<" ";
          cout<<(n+1)<<" ";
          for(int p=j;p<=n;p++) cout<<p<<" ";
          cout<<endl;
        }
        else{
          cout<<"-1"<<endl;
        }

      }
    }
    return 0;
}
