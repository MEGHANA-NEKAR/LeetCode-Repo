//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isSubsetSum(int arr[],int n, int sum){
       vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(arr[0]<=sum)dp[0][arr[0]] = true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(target >= arr[ind]) take = dp[ind-1][target - arr[ind]];
                
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][sum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i=0;i<N;i++){
            totalSum += arr[i];
        }
        if(totalSum%2==1) return false;
        int target = totalSum/2;
        return isSubsetSum(arr,N,target);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends