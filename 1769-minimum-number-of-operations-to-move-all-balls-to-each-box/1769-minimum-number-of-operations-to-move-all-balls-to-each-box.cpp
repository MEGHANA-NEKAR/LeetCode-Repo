class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector <int> ans(n);
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(boxes[j]=='1'){
                    sum+=abs(j-i);
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};
//time complexity:O(n^2);
//space complexity:O(n)