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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if ((list1 == NULL && list2 == NULL) || (list2 == NULL && list1 != NULL))
            return list1;
        if (list1 == NULL && list2 != NULL)
            return list2;

        ListNode *result, *p;
        if (list2->val <= list1->val)
            result = list2, list2 = list2->next;
        else
            result = list1, list1 = list1->next;

        p = result;

        for (; list1 != NULL && list2 != NULL;)
        {
            if (list2->val <= list1->val)
            {
                p->next = list2;
                list2 = list2->next;
            }
            else
            {
                p->next = list1;
                list1 = list1->next;
            }
            p = p->next;
        }

        if (list1 != NULL)
        {
            while (list1 != NULL)
                p->next = list1, p = p->next, list1 = list1->next;
        }
        if (list2 != NULL)
        {
            while (list2 != NULL)
                p->next = list2, p = p->next, list2 = list2->next;
        }
        return result;
    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
            if((list1==NULL && list2==NULL) || (list2==NULL && list1!=NULL))
                    return list1;
            if(list1==NULL && list2!=NULL)
                    return list2;
                    
            ListNode* result,*p;
            if(list2->val<=list1->val)
                    result=list2,list2=list2->next;
            else
                    result=list1,list1=list1->next;

            p=result;
            
            for(;list1!=NULL && list2!=NULL;)
            {
                if(list2->val<=list1->val)
                {
                        p->next=list2;
                        list2=list2->next;
                }
                 else
                {
                        p->next=list1;
                         list1=list1->next;
                        
                        
                }
                     p=p->next;
            }
            
            if(list1!=NULL)
            {
                    while(list1!=NULL)
                            p->next=list1,p=p->next,list1=list1->next;
            }
             if(list2!=NULL)
            {
                    while(list2!=NULL)
                            p->next=list2,p=p->next,list2=list2->next;
            }
            return result;
    }
};