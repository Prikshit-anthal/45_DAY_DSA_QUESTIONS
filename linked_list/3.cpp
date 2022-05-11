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
    int getDecimalValue(ListNode *head)
    {
        ListNode *node = head;
        int sum = 0;
        while (node != NULL)
        {

            sum = (sum << 1) | node->val;
            node = node->next;
        }
        cout << sum;
        return sum;
    }
};