class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {

        // append extra val to avoid null error
        // its better approach becoz no matha pachii
        ListNode *ans = new ListNode(-1000);
        ans->next = head;

        head = ans;

        // find val node
        ListNode *temp = head;
        ListNode *old = NULL;
        while (temp != NULL)
        {
            if (temp->val >= x)
                break;
            old = temp;
            temp = temp->next;
        }

        ListNode *old1 = old;

        while (temp != NULL)
        {
            if (temp->val < x)
            {
                ListNode *x = old->next;
                ListNode *y = temp->next;
                old->next = temp;
                temp->next = x;

                old1->next = y;
                old = old->next;
            };
            old1 = temp;
            temp = temp->next;
        }

        return head->next;
    }
};