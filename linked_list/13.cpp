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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *q = l1, *w = l2;
        int carry = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *curr = l3;

        while (q != NULL || w != NULL)
        {
            int sum = 0;
            if (q != NULL)
                sum += q->val;
            if (w != NULL)
                sum += w->val;
            sum += carry;

            carry = sum / 10;

            curr->val = sum % 10;

            if (q != NULL)
                q = q->next;
            if (w != NULL)
                w = w->next;
            if (q != NULL || w != NULL)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }

        // *curr=NULL;
        if (carry != 0)
            curr->next = new ListNode(carry);

        return l3;
    }
};