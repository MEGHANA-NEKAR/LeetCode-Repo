class Solution {
public:


string sortSentence(string s) {
    
    string ans="";
    
    
    vector<string>arr(10,"");
    int i=0,j=0;
    
    while(j<s.length()){
        if('0'<=s[j]&&'9'>=s[j]){
            arr[s[j]-'0'] = s.substr(i,j-i);
            j++;
            i=j;
        }
        if(s[j]==' '){
            i++;
        }
        j++;
    }
    
    for(int i=1;i<=arr.size();i++){
        if(arr[i+1]==""){
            ans+=arr[i];
            break;
        }
        ans+=arr[i]+" ";
    }
    return ans;
}
};
//time complexity: O(N)
//space complexity: O(1)