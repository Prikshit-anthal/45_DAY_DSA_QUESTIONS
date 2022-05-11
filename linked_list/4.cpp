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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL)
            return head;
        ListNode *node = head->next;
        ListNode *ret = head;
        int prev = head->val;
        while (node != NULL)
        {
            if (node->val == prev)
            {
                head->next = node->next;
                ListNode *temp = node;
                prev = node->val;
                node = node->next;

                delete temp;
            }
            else
            {
                head = head->next;
                prev = node->val;
                node = node->next;
            }
        }
        return ret;
    }
};