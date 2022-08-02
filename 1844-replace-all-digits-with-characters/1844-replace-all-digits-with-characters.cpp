class Solution {
public:
    
    char shift(char a,char integer){
        int n=integer-'0';
        return(a+n);
    }
    string replaceDigits(string s) {
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                s[i]=shift(s[i-1],s[i]);
            }
        }
        return s;
    }
};
//time complexity:O(n)
//space complexity:O(1)