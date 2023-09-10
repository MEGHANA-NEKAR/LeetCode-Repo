//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n = S.size();
        int l=0,r=0;
        int gl=0,gr=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            l = i;
            r = i;
            while(1){
                int newL = l-1;
                int newR = r+1;
                if(newL >= 0 && newR < n && S[newL] == S[newR]){
                    l = newL;
                    r = newR;
                }
                else{
                    break;
                }
            }
            int len = r-l+1;
            if(len > maxi){
                maxi = len;
                gl = l;
                gr = r;
            }
        }
        for(int i=0;i<n-1;i++){
            if(S[i] == S[i+1]){
                l = i;
                r = i+1;
                while(1){
                    int newL = l-1;
                    int newR = r+1;
                    if(newL >= 0 && newR < n && S[newL] == S[newR]){
                        l = newL;
                        r = newR;
                    }
                    else{
                        break;
                    }
                }
                int len = r-l+1;
                if(len>maxi){
                    maxi = len;
                    gl = l;
                    gr = r;
                }
            }
        }
        string res="";
        for(int i = gl;i<=gr;i++){
            res+=S[i];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends