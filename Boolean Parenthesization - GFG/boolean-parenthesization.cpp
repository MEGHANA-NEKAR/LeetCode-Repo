//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// #define ll long long

class Solution{
private:
    int mod = 1003;
    
    int f(int i,int j,int isTrue,string &s,vector<vector<vector<int>>>&dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue == 1) return s[i] == 'T'? 1:0;
            else return s[i] == 'F'?1:0;
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways = 0;
        for(int ind=i+1;ind<=j-1;ind+=2){
           
            int lT = f(i,ind-1,1,s,dp);
            int lF = f(i,ind-1,0,s,dp);
            int rT = f(ind+1,j,1,s,dp);
            int rF = f(ind+1,j,0,s,dp);
            
            if (s[ind] == '&') {
                if (isTrue) {
                    ways = (ways + (lT * rT) % mod) % mod;
                } else {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                }
            } else if (s[ind] == '|') {
                if (isTrue) {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                } else {
                    ways = (ways + (lF * rF) % mod) % mod;
                }
            } else if (s[ind] == '^') {
                if (isTrue) {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                } else {
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }

public:
    int countWays(int N, string s){
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return f(0,N-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends