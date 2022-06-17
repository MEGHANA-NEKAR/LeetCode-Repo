class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        char temp[n];
        for(int i=0;i<n;i++){
            temp[indices[i]]=s[i];
        }
        string ans="";
        for(int j=0;j<n;j++){
            ans+=temp[j];
        }
         return ans;   
    }
};
//time complexity=O(N)
//space complexity=O(N)