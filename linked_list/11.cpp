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
    bool isPalindrome(ListNode *head)
    {

        ListNode *temp = head;
        ListNode *last = NULL;
        int n = 0;

        while (temp != NULL)
        {
            last = temp;
            temp = temp->next;
            n++;
        }

        int x = 0;
        temp = head;
        while (x < n / 2)
        {
            temp = temp->next;
            x++;
        }

        if (n % 2 == 1)
            temp = temp->next;

        temp = reverseList(temp);

        while (temp != NULL)
        {
            if (temp->val != head->val)
                return false;
            // cout<<temp->val<<" "<<head->val<<endl;
            temp = temp->next;
            head = head->next;
        }
        return true;

        // return check_palin(n);
    }

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

    //     int check_palin(unsigned long long nn)
    //     {
    //        unsigned long long x=0;
    //        unsigned long long n=nn;

    //         cout<<nn<<" ";
    //         while(n!=0)
    //         {
    //             int r=n%10;
    //             x=x*10+r;
    //             n/=10;
    //         }
    //         return x==nn?true:false;
    //     }
};