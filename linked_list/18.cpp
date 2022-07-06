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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head, *n_back = NULL;
        int count = 0;

        while (temp != NULL)
        {
            if (count == n)
            {
                n_back = head;
            }
            else if (count > n)
            {
                n_back = n_back->next;
            }

            temp = temp->next;
            count++;
        }

        // exceptional two cases here
        if (count == 1)
            return NULL;
        if (n_back == NULL)
            return head->next;

        ListNode *delete_next = n_back->next->next;

        delete n_back->next;
        n_back->next = delete_next;

        return head;
    }
};