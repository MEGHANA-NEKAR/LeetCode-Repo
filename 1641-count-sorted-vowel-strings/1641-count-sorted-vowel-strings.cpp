class Solution {
public:
    
    int solve(int i,vector<char>& vowels,int n){
        if(i==5) return 0;
        if(n==0) return 1;
        
        return solve(i,vowels,n-1)+solve(i+1,vowels,n);
    }
    int countVowelStrings(int n) {
        vector<char> vowels{'a','e','i','o','u'};
        return solve(0,vowels,n);
    }
};
//time complexity:O(n)
//space complexity:O(n)