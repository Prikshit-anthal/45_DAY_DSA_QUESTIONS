class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *next = head;
        int n = 0;
        while (next != NULL)
        {
            n++;
            next = next->next;
        }
        next = head;
        for (int i = 0; i < n / 2; i++)
        {
            next = next->next;
        }
        return next;
    }
};