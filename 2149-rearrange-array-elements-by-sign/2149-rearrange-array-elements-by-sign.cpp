class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v;
        int i=0,j=i;
        while(v.size()!=nums.size()){
            if(v.size()%2==0){
                while(nums[i]<0)
                    i++;
                v.push_back(nums[i++]);
            }
            else{
                while(nums[j]>0)
                    j++;
                v.push_back(nums[j++]);
            }
        }
        return v;
        
    }
};
//time complexity:O(N)
//space complexity:O(N)