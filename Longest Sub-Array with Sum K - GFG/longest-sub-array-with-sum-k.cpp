//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int ,int>preSum;
        int sum = 0;
        int len = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum == k){
                len = max(len,i+1);
            }
            int rem = sum - k;
            if(preSum.find(rem)!=preSum.end()){
                len = max(len, i - preSum[rem]);
            }
            if(preSum.find(sum) == preSum.end()){
                preSum[sum] = i;
            }
        }
        return len;
    } 

};




//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends