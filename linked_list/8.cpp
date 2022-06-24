long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here

    long long m = 1e9 + 7;
    Node *temp1 = l1;
    long long count1 = 0, count2 = 0;
    while (temp1 != NULL)
    {
        count1 = ((count1 * 10) + temp1->data) % m;
        temp1 = temp1->next;
    }

    temp1 = l2;
    while (temp1 != NULL)
    {
        count2 = ((count2 * 10) + temp1->data) % m;
        temp1 = temp1->next;
    }

    //   s1=s1%m;
    //   s2=s2%m;
    return (count1 * count2) % m;
    // return 0;
}