//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  int perfectSum(vector<int>&arr, int n, int sum)
	{
	    vector<int>prev(sum+1,0),curr(sum+1,0);
	    int mod = 1e9+7;
	    if(arr[0] == 0) prev[0] = 2;
	    else prev[0] = 1;
	    if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
	    
	    for(int ind = 1;ind<n;ind++){
	        for(int target = 0;target <=sum;target++){
	            int notTake = prev[target];
	            int take = 0;
	            if(target>=arr[ind]) take = prev[target - arr[ind]];
	            curr[target] = (notTake + take)%mod;
	        }
	        prev = curr;
	    }
        return prev[sum];
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