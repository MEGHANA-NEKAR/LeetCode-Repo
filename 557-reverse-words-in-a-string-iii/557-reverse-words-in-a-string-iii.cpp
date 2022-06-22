class Solution {
public:
    string reverseWords(string s) {
        int start =0;
        for(int i=0;i<s.length();i++){
            if(int(s[i])==32)
            {
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};
//time complexity:O(n)
//space complexity:O(n)