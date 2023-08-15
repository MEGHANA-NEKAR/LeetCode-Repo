//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:
    int knapSack(int N, int W, int val[], int wt[])
    {   
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        for(int t=0;t<=W;t++){
            dp[0][t] = ((int)(t/wt[0]))*val[0];
        }
        for(int ind=1;ind<N;ind++){
            for(int target = 0;target<=W;target++){
                int notTake = dp[ind-1][target];
                int take = 0;
                if(target >= wt[ind]) take = val[ind] + dp[ind][target - wt[ind]];
                dp[ind][target] = max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends