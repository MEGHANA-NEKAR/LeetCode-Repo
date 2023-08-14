//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totalSum = 0;
	    for(int i=0;i<n;i++){
	        totalSum += arr[i];
	    }
	    
	    int sum = totalSum;
        vector<bool>prev(sum+1,0);
        vector<bool>curr(sum+1,0);
        prev[0] = curr[0] = true;
        if(arr[0]<=sum) prev[arr[0]] = true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[ind]) take = prev[target - arr[ind]];
                
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        
        int mini = 1e9;
        for(int s1=0;s1 <= totalSum/2;s1++){
            if(prev[s1] == true){
                mini = min(mini,abs((totalSum-s1)-s1));
            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends