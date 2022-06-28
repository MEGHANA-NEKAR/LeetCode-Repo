class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int len=s.length();
        for(int i=len-1;i>=0;i--){
            if(s[i]=='#'){
                res = char(stoi(s.substr(i-2,2))+96)+res;
                i-=2;
            }
            else
                res=char(96+s[i]-'0')+res;
        }
        return res;
    }
};
//time complexity:O(n)
//space complexity:O(1)