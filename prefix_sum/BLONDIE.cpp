#include<bits/stdc++.h>
using namespace std;
long long int arr[100005],n,t,sum;
int main(){
    cin>>t;
    while(t--){
      cin>>n;
      for(int i=0;i<n;i++)
          cin>>arr[i];
      sum=0;
      for(int i=0;i<n;i++){
          if(arr[i]>0) sum+=arr[i];
          else {
            arr[i]=sum/(i);
            sum+=arr[i];
          }
      }
      for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
      cout<<endl;
    }
    return 0;
}
