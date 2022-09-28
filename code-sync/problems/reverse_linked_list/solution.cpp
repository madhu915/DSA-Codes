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
    ListNode* reverseList(ListNode* head) {
        // iterative
        if(head==NULL)
            return NULL;
        //3pointers
        ListNode* prev=NULL,*curr=head,*nextp;
        while(curr!=NULL){
            nextp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextp;
        }
        // after curr reached eol prev points to reversed head
        return prev;
    }
};