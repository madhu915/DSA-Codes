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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        //BF
        while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
    }
};