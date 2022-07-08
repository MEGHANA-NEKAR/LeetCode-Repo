class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        for(int i=n-1;i>0;i--){
            if(i%2!=0){
                ans=ans+(n-i);
            }
        }
        return ans;
    }
};
//time complexity:O(n)
//space complexity:O(1)