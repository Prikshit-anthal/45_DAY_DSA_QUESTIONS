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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *forward = head;
        ListNode *old = NULL;
        ListNode *temp = NULL;

        while (forward != NULL)
        {
            temp = forward;
            forward = forward->next;

            temp->next = old;
            old = temp;
        }

        return temp;
    }
};