class Solution {
public:
    int numberOfSteps(int num) {
        int m=0;
        while(num>0){
            if(num%2==0){
                num/=2;
               
            }
            else if(num%2!=0){
                num-=1;
        
            }
            m++;
        }
        return m;
    }
};
//time complexity: O(n)
//space complexity:O(1)