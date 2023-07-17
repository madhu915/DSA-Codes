/*
    Time Complexity: O('m' + 'n')
    Space Complexity: O(1)

    Where 'm' and 'n' are the lengths of the linked lists.
*/
/*
1->2->3->NULL
2->3->8->NULL
O/P: 3->5->1->1->NULL
*/
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // 'node1' and 'node2' point to the current node of the first and second list, respectively.
    Node *node1 = num1;
    Node *node2 = num2;

    // 'sum' and 'carry' store the sum and carry generated in the current iteration.
    int sum = 0, carry = 0;

    Node *prev = NULL;

    while (node1 != NULL && node2 != NULL)
    {
        // Add the values in the current nodes along with the carry.
        sum = node1->data + node2->data + carry;

        // Store the next node of the sum list in the current node of the first linked list.
        node1->data = sum % 10;

        // Get the new carry.
        carry = sum / 10;

        // Keep track of the previous node.
        prev = node1;

        // Move to the next node
        node1 = node1->next;
        node2 = node2->next;
    }

    // If there are remaining digits in any one of the lists, add them to the sum list.
    if (node1 != NULL || node2 != NULL)
    {
        if (node2 != NULL)
        {
            prev->next = node2;
        }

        node1 = prev->next;

        while (node1 != NULL)
        {
            // Add the values in the current node along with the carry.
            sum = node1->data + carry;

            // Store the next node of the sum list in the current node of the first linked list.
            node1->data = sum % 10;

            // Get the new carry.
            carry = sum / 10;

            // Keep track of the previous node.
            prev = node1;

            // Move to the next node
            node1 = node1->next;
        }
    }

    if (carry > 0)
    {
        // Carry is generated from the last iteration. So, add a new node to the sum list.
        prev->next = new Node(carry);
    }

    // Return the head of the sum list.
    return num1;
}
