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
    ListNode *removeElements(ListNode *head, int val)
    {

        if (head == NULL)
            return head;
        while (head->val == val)
        {
            ListNode *temp = head;
            if (head->next == NULL)
                return head->next;
            head = head->next;
            delete temp;
        }
        ListNode *node = head->next;
        ListNode *prev = head;
        while (node != NULL)
        {
            if (node->val == val)
            {
                ListNode *temp = node;
                node = node->next;
                prev->next = node;
                delete temp;
            }
            else
            {
                prev = prev->next;
                node = node->next;
            }
        }
        return head;
    }
};