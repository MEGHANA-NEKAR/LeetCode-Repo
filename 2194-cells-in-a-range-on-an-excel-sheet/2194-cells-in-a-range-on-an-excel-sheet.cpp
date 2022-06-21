class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for(int i=s[0]; i<=s[3]; i++) {
            for(int j=s[1]; j<=s[4]; j++) {
                char n = (char)i;
                char m = (char)j;
                string k = "";
                k = k + n + m;
                ans.push_back(k);
            }
        }
        return ans;
    }
};
//
//time complexity:O((s[3]-s[0])*(s[1]-s[4]))^2)==>approx. O(n^2)
//space complexity:O((s[3]-s[0])*(s[1]-s[4]))^2)==>approx. O(n^2)