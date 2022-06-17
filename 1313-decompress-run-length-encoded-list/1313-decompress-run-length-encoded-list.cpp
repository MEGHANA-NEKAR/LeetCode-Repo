class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans;
        int freq =0;
        int val=0;
        int k=0;
        
        
        for(int i=0;i<n;i+=2){
            freq=nums[i];
            val=nums[i+1];
            for(int j=0;j<freq;j++){
                ans.push_back(val);
                k++;
            }
        }
        return ans;
    }
};

//time complexity=O(N^2)
//space complexity=O(N)