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
      // stack approach instead of LL reversal
        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        // push all l1 nodes
        while (l1) {
        stack1.push(l1);
        l1 = l1->next;
        }
        // push all l2 nodes
        while (l2) {
        stack2.push(l2);
        l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;
        // either both stacks are not empty 
        // or a new node with remaining carry is yet to be added
        while (carry || !stack1.empty() || !stack2.empty()) {
        if (!stack1.empty()){
            carry += stack1.top()->val; 
            stack1.pop();
        }
        if (!stack2.empty()){
            carry += stack2.top()->val;
            stack2.pop();
        }
        ListNode* node = new ListNode(carry % 10);
        carry/=10;
        // reverse the node order + update head
        node->next = head;
        head = node;
        }

        return head;
    }
};
