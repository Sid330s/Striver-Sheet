#include<bits/stdc++.h>
using namespace std;

int arr[105][105],brr[105][105];
int n,m;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>arr[i][j];

  int hr[n];
  int hc[m];

  for(int i=0;i<n;i++)
    hr[i]=1;

  for(int j=0;j<m;j++)
    hc[j]=1;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
       if(arr[i][j]==0) hc[j]=0,hr[i]=0;


  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++)
     if(hr[i]==0 || hc[j]==0)
       brr[i][j]=0;
     else
       brr[i][j]=1;
   }


   for(int i=0;i<n;i++)
     hr[i]=1;

   for(int j=0;j<m;j++)
     hc[j]=1;

   for(int i=0;i<n;i++){
     bool rf=true;
     for(int j=0;j<m;j++)
        if(brr[i][j]==1){
           rf=false;
           break;
        }
     if(rf) hr[i]=0;
   }

   for(int j=0;j<m;j++){
     bool cf=true;
     for(int i=0;i<n;i++)
        if(brr[i][j]==1){
           cf=false;
           break;
        }
     if(cf) hc[j]=0;
   }



  bool flag =true;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
       if( arr[i][j]==1 && hc[j]==0 && hr[i]==0 || arr[i][j]==0 && (hc[j]==1 || hr[i]==1) ){
            flag=false;
            break;
       }

  if(flag){
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
        cout<<brr[i][j]<<" ";
       cout<<endl;
      }
  }
  else{
    cout<<"NO"<<endl;
  }

  return 0;
}
