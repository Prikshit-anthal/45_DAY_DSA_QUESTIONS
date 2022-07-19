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

        ListNode *old = new ListNode(-1001);
        ListNode *prev = new ListNode(-1000);

        old->next = prev;
        prev->next = head;

        ListNode *temp = head;
        ListNode *tempo = old;

        bool help = false;

        while (temp != NULL)
        {
            if (temp->val == prev->val)
            {
                help = true;
            }
            else if (help)
            {
                old->next = temp;
                help = false;
            }
            else
            {
                old = old->next;
            }

            prev = temp;
            temp = temp->next;
        }

        if (help)
            old->next = temp;

        return tempo->next->next;
    }
};