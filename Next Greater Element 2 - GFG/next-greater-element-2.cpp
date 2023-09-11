//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        stack<int>st;
        vector<int>res(N,-1);
        for(int i=2*N-1;i>=0;i--){
            while(!st.empty() && arr[i%N] >= st.top()){
                st.pop();
            }
            if(i<N){
                if(!st.empty()) res[i] = st.top();
                else res[i] = -1;
            }
            st.push(arr[i%N]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends