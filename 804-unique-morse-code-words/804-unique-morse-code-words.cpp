class Solution {
public:
    string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>ans;
        for(int i=0;i<words.size();i++)
        {
            string p;
            for(int j=0;j<words[i].size();j++)
            {
                p=p+s[words[i][j]-'a'];
            }
            ans.insert(p);
        }
        return ans.size();
    }
};
//time complexity:O(n^2)
//space complexity:O(n)