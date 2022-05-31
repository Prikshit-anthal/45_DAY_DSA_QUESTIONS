class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q == NULL)
            return false;
        if (p == NULL && q != NULL)
            return false;
        if (p->val != q->val)
            return false;

        bool res1 = isSameTree(p->left, q->left);
        if (!res1)
            return res1;
        bool res2 = isSameTree(p->right, q->right);

        return res2;
    }
};