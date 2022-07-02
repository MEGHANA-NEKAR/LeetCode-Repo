class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.length()){
            if(word[i]==ch){
                reverse(word.begin(),word.begin()+i+1);
                break;
            }
            i++;
        }
        return word;
    }
};
//time complexity:O(n)
//space complexity:O(1)