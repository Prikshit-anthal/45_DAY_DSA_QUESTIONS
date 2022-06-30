class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> x;
        stack<int> y;

        while (l1)
        {
            x.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            y.push(l2->val);
            l2 = l2->next;
        }

        stack<int> ans;
        int c = 0;
        while (!x.empty() && !y.empty())
        {
            int p = x.top() + y.top() + c;
            c = p / 10;
            ans.push(p % 10);
            x.pop();
            y.pop();
        }
        while (x.empty() && !y.empty())
        {
            int p = y.top() + c;
            c = p / 10;
            ans.push(p % 10);
            y.pop();
        }
        while (y.empty() && !x.empty())
        {
            int p = x.top() + c;
            c = p / 10;
            ans.push(p % 10);
            x.pop();
        }

        if (c != 0)
            ans.push(c);

        ListNode *head, *a;

        head = new ListNode(ans.top());
        ans.pop();
        a = head;
        while (!ans.empty())
        {
            a->next = new ListNode(ans.top());
            a = a->next;
            ans.pop();
        }
        return head;
    }
};