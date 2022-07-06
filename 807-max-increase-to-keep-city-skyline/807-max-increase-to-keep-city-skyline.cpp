class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int original = grid[i][j];
                int max1=INT_MIN;
                int max2=INT_MIN;
                for(int k=0;k<n;k++){
                    max1=max(max1,grid[i][k]);
                }
                for(int k=0;k<n;k++){
                    max2=max(max2,grid[k][j]);
                }
                count+=abs(original-min(max1,max2));
            }
        }
        return count;
            
    }
};
//time complexity:O(n^3)
//space complexity:O(n)