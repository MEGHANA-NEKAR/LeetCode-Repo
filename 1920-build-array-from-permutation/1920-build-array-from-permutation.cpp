class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        vector<int> ans(n);
        while(i<n){
            ans[i] = nums[nums[i]];
            i++;
        }
        return ans;
    }
};
//time complexity: O(N)
// space complexity: O(N)