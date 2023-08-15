//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  
  public:
    int cutRod(int price[], int n) {
        vector<int>prev(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i] = i*price[0];
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=n;target++){
                int notTake = prev[target];
                int take = -1e9;
                int rodLength = ind+1;
                if(rodLength <= target) take = price[ind] + prev[target - rodLength];
                prev[target] = max(take,notTake);
            }
        }
        return prev[n];
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