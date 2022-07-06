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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *temp = head;
        ListNode *old = NULL;
        int count = 1;
        while (temp != NULL)
        {
            if (count == left)
            {
                ListNode *temp1 = temp;
                while (count != right)
                {

                    temp1 = temp1->next;
                    count++;
                }
                temp1 = temp1->next;

                ListNode *rev = reverse(temp, temp1);
                temp->next = temp1;

                // cout<<rev->val<<endl;

                if (old) // old not null
                    old->next = rev;
                else // old null
                    head = rev;
                break;
            }
            count++;
            old = temp;
            temp = temp->next;
        }
        return head;
    }

    ListNode *reverse(ListNode *head, ListNode *tail)
    {
        ListNode *forward = head;
        ListNode *old = NULL;
        ListNode *temp = NULL;

        while (forward != tail)
        {
            temp = forward;
            forward = forward->next;

            temp->next = old;
            old = temp;
        }

        return temp;
    }
};