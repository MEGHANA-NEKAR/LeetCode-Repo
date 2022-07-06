class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        vector <int> lasers;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1')
                    temp++;
                
            }
            if(temp){lasers.push_back(temp);}
        }
        int count =0;n=lasers.size();
        if(n==1)return 0;
        
        for(int i=0;i<n-1;i++){
            count+=lasers[i]*lasers[i+1];
        }
        return count;
        
    }
};
//time complexity:O(n^2)
//space complexity:O(n)