/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *temp = headA;
        ListNode *old = NULL;

        while (temp != NULL)
        {
            old = temp;
            temp = temp->next;
        }

        old->next = headB;

        // now floyd cycle algo
        ListNode *ans = floyd_cycle(headA);
        old->next = NULL;
        return (ans);
        // return NULL;
    }

    ListNode *floyd_cycle(ListNode *head)
    {
        // fas and slow
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != slow && fast != NULL)
        {
            if (fast->next == NULL)
            {
                fast = NULL;
                break;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast == NULL)
            return NULL;

        slow = head;
        fast = fast->next;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};