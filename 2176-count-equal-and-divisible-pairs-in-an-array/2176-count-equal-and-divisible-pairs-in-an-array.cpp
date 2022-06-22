class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[i]==nums[j] && (i*j)%k==0)
                    count++;
            }
        }
        return count;
    }
};
//time complexity:O(n^2)
//space complexity:O(1)