class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        for(int i=0;i<n/2;i++){
            int sum=0;
            sum+=nums[i]+nums[n-1-i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
//time complexity:O(nlogn)
//space complexity:O()