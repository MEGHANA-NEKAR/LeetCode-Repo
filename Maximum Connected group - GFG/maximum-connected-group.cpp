//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
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
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  private:
    bool isValid(int nrow,int ncol,int n){
        return (nrow < n && nrow>=0 && ncol<n && ncol>=0);
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int oneCount = 0;
        for(int row=0;row<n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col] == 1){
                    oneCount++;
                    for(int i=0;i<4;i++){
                        int nrow = row+delrow[i];
                        int ncol = col+delcol[i];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1){
                            int nodeNo = row * n + col;
                            int adjNo = nrow * n + ncol;
                            ds.unionBySize(nodeNo,adjNo);
                        }
                    }
                }
            }
        }
        if(oneCount == n*n) return n*n;
        int maxi = 0;
        for(int row = 0;row<n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col] == 0){
                    set<int>comp;
                    for(int i=0;i<4;i++){
                        int nrow = row+delrow[i];
                        int ncol = col+delcol[i];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1){
                            int node = nrow * n + ncol;
                            comp.insert(ds.findUParent(node));
                        }
                    }
                    int totalSize = 1;
                    for(auto it:comp){
                        totalSize += ds.size[it];
                    }
                    maxi = max(maxi,totalSize);
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends