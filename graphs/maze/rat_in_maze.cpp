// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    char step(int k){
        if(k==0){
            return 'D';
        }
        else if(k==1){
            return 'L';
        }
        else if(k==2){
            return 'R';
        }
        else {
            return 'U';
        }
    }
    bool isSafe(int i,int j,int n,vector<vector<int>> &m,vector<vector<bool>> &vis){
        if(i>=n || j>=n || i<0 || j<0 || vis[i][j]|| !m[i][j]) return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>> &m, int n,vector<vector<bool>> &vis,vector<string> & res,string contri){
        int x[4]={1,0,0,-1};
        int y[4]={0,-1,1,0};

        if(i==n-1 && j==n-1) {
            res.push_back(contri);
            return;
        }


        vis[i][j]=true;
        for(int k=0;k<4;k++){
            if(isSafe(i+x[k],j+y[k],n,m,vis)){
                dfs(i+x[k],j+y[k],m,n,vis,res,contri+step(k));
            }

        }
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<string> res;
        if(isSafe(0,0,n,m,vis)) dfs(0,0,m,n,vis,res,"");
        return res;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
