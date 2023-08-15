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
        vector<int>prev(W+1,0);
        for(int t=0;t<=W;t++){
            prev[t] = ((int)(t/wt[0]))*val[0];
        }
        for(int ind=1;ind<N;ind++){
            for(int target = 0;target<=W;target++){
                int notTake = prev[target];
                int take = 0;
                if(target >= wt[ind]) take = val[ind] + prev[target - wt[ind]];
                prev[target] = max(take,notTake);
            }
        }
        return prev[W];
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