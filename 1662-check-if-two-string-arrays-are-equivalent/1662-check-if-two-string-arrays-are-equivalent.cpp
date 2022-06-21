class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string n="";
        string m="";
        n=accumulate(word1.begin(),word1.end(),n);
        m=accumulate(word2.begin(),word2.end(),m);
        if(n==m)
            return true;
        
        else
            return false;
            
    }
};
//time complexity: O(n)
//space complexity: O(1)