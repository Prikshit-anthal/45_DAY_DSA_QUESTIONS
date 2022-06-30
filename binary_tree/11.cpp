/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
    TreeNode *anss;
    TreeNode *p, *q;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        this->p = p;
        this->q = q;

        vector<int> arr = helper(root);

        return anss;
    }

    vector<int> helper(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        vector<int> ans(2, 0);

        if (root->val == p->val)
            ans[0] = 1;
        if (root->val == q->val)
            ans[1] = 1;

        vector<int> ans1 = helper(root->left);

        vector<int> ans2 = helper(root->right);

        if (ans[0] == 1 || ans1[0] == 1 || ans2[0] == 1)
            ans[0] = 1;
        if (ans[1] == 1 || ans1[1] == 1 || ans2[1] == 1)
            ans[1] = 1;

        if (ans[0] == ans[1] && ans[0] == 1)
        {
            anss = root;
            ans[0] = -1;
            ans[1] = -1;
        }

        return ans;
    }
};