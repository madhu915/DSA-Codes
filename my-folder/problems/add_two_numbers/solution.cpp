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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {               
        if(!l1 && !l2)
            return nullptr;
        else if(!l1)
            return l2;
        else if(!l2)
            return l1;
        int vl=((l1->val)+(l2->val));        

        ListNode* sum=new ListNode(vl%10);       
        sum->next=addTwoNumbers(l1->next,l2->next);
        if(vl>=10){
            sum->next=addTwoNumbers(sum->next,new ListNode(1));
        }
        return sum;
        
    }
};