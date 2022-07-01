/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string nums;
        while(head!=NULL){
            nums+=to_string(head->val);
            head=head->next;
        }
        int n=nums.size();
        int ans=0,multiple=1;
        for(int i=n-1;i>=0;i--){
            ans+=multiple*(stoi(nums.substr(i,1)));
            multiple *= 2;
        }
        return ans;
    }
};
//time complexity:O(n)
//space complexity:O(n)