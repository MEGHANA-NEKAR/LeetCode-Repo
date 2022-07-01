class Solution {
public:
    bool checkIfPangram(string sentence) {
        int o[26]={0};
        
        for(int i=0;i<sentence.size();i++)
            o[sentence[i]-'a']++;
        
        for(int i=0;i<26;i++){
            if(o[i]==0)
                return false;
        }
        return true;
    }
};
//time complexity:O(n)
//space complexity:O(1)