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
    ListNode* tmp;
    bool checker(ListNode* head){
        if(head==NULL)
            return true;
        bool ans=checker(head->next) & (tmp->val==head->val);
        tmp=tmp->next;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        tmp=head;
       return checker(head);        
    }
};