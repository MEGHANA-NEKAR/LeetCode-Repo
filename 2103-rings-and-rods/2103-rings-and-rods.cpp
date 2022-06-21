class Solution {
public:
    int countPoints(string rings) {
        int count =0;
        vector<int> rods(10,0);
        //let R,G and B each represent a bit
        for(int i=0;i<rings.length();i+=2){
            char color=rings[i];
            int rod=rings[i+1]-'0';
            
            if(color=='R')
                rods[rod] |= 1<<0;
            else if(color=='G')
                rods[rod] |= 1<<1;
            else if(color=='B')
                rods[rod] |= 1<<2;
                
           }
        for(int k=0;k<rods.size();k++){
            count+=rods[k]==7?1:0;
        }
        return count;
        
    }
};
//time complexity: O(n);
//space complexity: O(n);