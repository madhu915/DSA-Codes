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
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
       if(head==NULL)
           return NULL;
        ListNode* s=head,*f=head;
        while(n--)
            f=f->next;
        
        while(f!=NULL and f->next!=NULL){
            s=s->next;
            f=f->next;            
        }
        
        //remove head
        if(f==NULL){
            ListNode* tmp=head;
            head=head->next;
            delete(tmp);            
        }
        else{
            ListNode* tmp=s->next;
            s->next=tmp->next;
            delete(tmp);
        }
        return head;
        
    }
};