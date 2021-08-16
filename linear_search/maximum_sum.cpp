#include<bits/stdc++.h>
using namespace std;
long long int max_ele;
long long int arr[100005],n,max_sum,max_count;
int main(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    max_ele = -10000000000;

    for(int i=0;i<n;i++)
        max_ele=max(max_ele,arr[i]);

    // cout<<"->"<<max_ele<<endl;
    max_sum=0;
    max_count=0;
    for(int i=0;i<n;i++)
        if(arr[i]>=0){
            max_sum=max_sum+arr[i];
            max_count++;
        }

    if(max_ele<0)
        cout<<max_ele<<" "<<1<<endl;
    else
        cout<<max_sum<<" "<<max_count<<endl;


    return 0;
}
