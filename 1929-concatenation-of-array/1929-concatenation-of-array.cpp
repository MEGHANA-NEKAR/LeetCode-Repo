class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(2*n);
        int i= 0;
        while(i < n){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
            i++;
        }
        return ans;
    }
};
//time complexity: O(N)
// space complexity: O(N)