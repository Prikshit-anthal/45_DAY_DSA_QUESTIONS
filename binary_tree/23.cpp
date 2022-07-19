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
public:
    bool isValidBST(TreeNode *root)
    {

        return helper(root, long(INT_MIN) - 1, long(INT_MAX) + 1); // see here long(INT_MIN-1) doesnt work
        // coz vo int ki trh he calcu krta andr badmain long main
        // isse aacha pehel he long bna lo
    }

    bool helper(TreeNode *root, long min, long max)
    {
        if (root == NULL)
            return true;

        if (root->val >= max)
            return false;
        if (root->val <= min)
            return false;

        if (!helper(root->left, min, root->val))
            return false;
        return helper(root->right, root->val, max);
    }
};