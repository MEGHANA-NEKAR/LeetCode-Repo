class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans=0,k=0;
        while(k<piles.size()/3){
            ans+=piles[2*k+1];
            k++;
        }
        return ans;
    }
};
//time complexity:O(nlogn)
//space complexity:O(n)