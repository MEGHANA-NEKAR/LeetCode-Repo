class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n= nums.size();
        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(nums[i]==nums[j]){
                    counter++;
                }
            }
        }
        return counter;
    }
};
//O(N^2)