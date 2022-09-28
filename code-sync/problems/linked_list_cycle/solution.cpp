/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 2pointer
        if(!head)
            return false;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
            
        }
        return false;
    }
};