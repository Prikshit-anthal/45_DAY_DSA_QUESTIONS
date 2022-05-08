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
    int low, high, sum = 0;

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        this->low = low;
        this->high = high;
        transversal(root);
        return sum;
    }

    void transversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->val <= high && root->val >= low)
            sum += root->val;
        transversal(root->left);
        transversal(root->right);
    }
};