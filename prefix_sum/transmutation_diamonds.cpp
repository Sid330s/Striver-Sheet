#include<bits/stdc++.h>
using namespace std;
long long int arr[150][150],brr[150][150],n,m,t,res,ans;
bool isValid(int i,int j,int k){
    if( i + 2*k-1 > n || j + k > n ||  j - k < 1 )
      return false;
    return true;
}
int main(){
    cin>>t;
    while(t--){
      cin>>n;
      for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) arr[i][j]=0;
      for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) brr[i][j]=0;

      for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>arr[i][j];
      for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) brr[i][j]=arr[i][j];

      for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) brr[i][j]=brr[i][j]+brr[i+1][j]+brr[i+1][j+1]+brr[i+1][j-1];

      for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
          int k=1;
          while(isValid(i,j,k)){
             ans=0;
             ans=brr[i][j] + brr[i+k+1][j-k] ;
             
             k++
          }

      }



    }

    cin>>n>>m>>u>>q;


    while(u--){
      cin>>k>>r1>>c1>>r2>>c2;
      r1++;
      c1++;
      r2++;
      c2++;
      brr[r1][c1]+=k;
      brr[r2+1][c2+1]+=k;
      brr[r2+1][c1]-=k;
      brr[r1][c2+1]-=k;
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
      brr[i][j]+=brr[i][j-1] + brr[i-1][j] - brr[i-1][j-1];

    // for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++) cout<<brr[i][j]<<" ";
    //   cout<<endl;
    // }

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
      brr[i][j] = arr[i][j] + brr[i][j];

    // for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++) cout<<brr[i][j]<<" ";
    //   cout<<endl;
    // }

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
      brr[i][j]+=brr[i][j-1] + brr[i-1][j] - brr[i-1][j-1];



    while(q--){
      cin>>r1>>c1>>r2>>c2;
      r1++;
      c1++;
      r2++;
      c2++;
      res = brr[r2][c2] + brr[r1-1][c1-1] - brr[r2][c1-1] - brr[r1-1][c2];
      cout<<res<<endl;
    }


    return 0;
}
