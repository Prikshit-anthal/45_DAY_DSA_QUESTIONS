/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    vector<int> res;

public:
    bool isSymmetric(TreeNode *root)
    {

        // return two_transversal_recursion(root->left,root->right);
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root->left, root->right});
        return iterative(q);
    }

    bool two_transversal_recursion(TreeNode *left, TreeNode *right)
    {
        if ((left == NULL && right != NULL) || (right == NULL && left != NULL))
            return false;
        if (left == NULL && right == NULL)
            return true;
        if (left->val != right->val)
            return false;
        bool one = two_transversal_recursion(left->left, right->right);
        if (!one)
            return false;
        bool two = two_transversal_recursion(left->right, right->left);
        if (two && one)
            return true;
        else
            return false;
    }

    bool iterative(queue<pair<TreeNode *, TreeNode *>> q)
    {

        while (!q.empty())
        {
            TreeNode *left = q.front().first;
            TreeNode *right = q.front().second;

            q.pop();

            if ((left == NULL && right != NULL) || (right == NULL && left != NULL))
                return false;
            if (left == NULL && right == NULL)
                continue;
            if (left->val != right->val)
                return false;

            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }
        return true;
    }
};