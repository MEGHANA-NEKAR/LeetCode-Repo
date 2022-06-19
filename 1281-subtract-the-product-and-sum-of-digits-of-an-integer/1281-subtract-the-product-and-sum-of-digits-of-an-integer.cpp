class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> ans;
        int m;
        int p=1;
        int s=0;
        
        while(n>0){
            m = n % 10;
            ans.push_back(m);
            n/=10;
        }
        int k=ans.size();
        for(int i=0;i<k;i++){
            p=p*ans[i];
        }
        
        for(int j=0;j<k;j++){
            s=s+ans[j];
        }

        int result = (p - s);
        return result;
    }
};
//time complexity: O(N)
// space complexity: O(N)