//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  int perfectSum(vector<int>&arr, int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	    int mod = 1e9+7;
	    if(arr[0] == 0) dp[0][0] = 2;
	    else dp[0][0] = 1;
	    if(arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;
	    
	    for(int ind = 1;ind<n;ind++){
	        for(int target = 0;target <=sum;target++){
	            int notTake = dp[ind-1][target];
	            int take = 0;
	            if(target>=arr[ind]) take = dp[ind-1][target - arr[ind]];
	            dp[ind][target] = (notTake + take)%mod;
	        }
	    }
        return dp[n-1][sum];
	}
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(auto it:arr){
            totalSum+=it;
        }
        if(totalSum - d < 0 || (totalSum - d)%2 == 1)return 0;
        return perfectSum(arr,n,(totalSum-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends