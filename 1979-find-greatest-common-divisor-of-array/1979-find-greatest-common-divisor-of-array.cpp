class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return GCD(nums[0],nums[n-1]);
    }
    int GCD(int a,int b){
        vector<int> list;
        for(int i=1;i<=a && i<=b ;i++){
            if(a%i==0 && b%i==0)
                list.push_back(i);
        }
        return *max_element(list.begin(),list.end());
    }
    
};
//time complexity:O(nlogn)
//space complexity:O(n)