class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0,x,y;
        int n=points.size();
        
        for(int i=1;i<n;i++){
            x=abs(points[i-1][0]-points[i][0]);
            y=abs(points[i-1][1]-points[i][1]);
            ans+=min(x,y)+abs(x-y);
        }
        return ans;
    }
};
//time complexity:O(n)
//space complexity:O(n)