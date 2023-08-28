//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int f(int ind,int target,int arr[], vector<vector<int>>&dp){
        int mod = 1e9+7;
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = f(ind-1,target,arr,dp)%mod;
        int take = 0;
        if(target >= arr[ind]){
            take = f(ind-1,target-arr[ind],arr,dp)%mod;
        }
        return dp[ind][target] = (take+notTake)%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends