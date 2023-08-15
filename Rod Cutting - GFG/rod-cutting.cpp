//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = i*price[0];
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=n;target++){
                int notTake = dp[ind-1][target];
                int take = -1e9;
                int rodLength = ind+1;
                if(rodLength <= target) take = price[ind] + dp[ind][target - rodLength];
                dp[ind][target] = max(take,notTake);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends