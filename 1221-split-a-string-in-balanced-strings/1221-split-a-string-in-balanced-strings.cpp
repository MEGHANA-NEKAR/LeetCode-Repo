class Solution {
public:
    int balancedStringSplit(string s) {
        string ans;
        int r=0;
        int l=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            ans+=s[i];
            //ans+=s[i+1];
            if(ans[i]=='R')
                r++;
            else if(ans[i]=='L')
                l++;
            if(r==l){
                count++;
            }
            
        }
        return count;
    }
};
//time complexity:O(N)
//space complexity:O(N) 