class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string dest=paths[0][1];
        
        for(int i=0;i<paths.size();++i){
            if(dest==paths[i][0])
                dest=paths[i][1],i=-1;
        }
        //return paths[paths.size()-1][1];
        return dest;
    }
};
//time complexity:O(n)
//space complexity:O(1)