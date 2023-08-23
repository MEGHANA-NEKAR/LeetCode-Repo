//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        vector<int>ans;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >=0){
                    if(vis[nrow][ncol] == 1){
                        int nodeNo = row * m + col;
                        int adjNo = nrow * m + ncol;
                        if(ds.findUParent(nodeNo) != ds.findUParent(adjNo)){
                            count--;
                            ds.unionBySize(nodeNo,adjNo);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends