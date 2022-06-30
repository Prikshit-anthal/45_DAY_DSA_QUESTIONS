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
    TreeNode *subRoot, root;

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == NULL)
            return true;
        return transversal(root, subRoot);
    }

    bool transversal(TreeNode *root, TreeNode *subRoot)
    {

        if (root == NULL)
            return false;

        bool check = false;

        if (root->val == subRoot->val)
            check = checker(root, subRoot);

        if (check == true)
            return true;

        if (root->left != NULL)
            check = transversal(root->left, subRoot);
        if (check == true)
            return true;
        if (root->right != NULL)
            check = transversal(root->right, subRoot);

        return check;
    }
    bool checker(TreeNode *root, TreeNode *subRoot)
    {
        // cout<<root->val<<" "<<subRoot->val<<endl;
        if (root->val != subRoot->val || (root->left == NULL && subRoot->left != NULL) || (subRoot->left == NULL && root->left != NULL) || (root->right == NULL && subRoot->right != NULL) || (subRoot->right == NULL && root->right != NULL))
        {
            return false;
        }

        bool check = true;
        if (root->left != NULL)
            check = checker(root->left, subRoot->left);
        // cout<<check<<" b ";
        if (check == false)
            return false;

        if (root->right != NULL)
            check = checker(root->right, subRoot->right);
        // cout<<check<<endl;
        if (check == false)
            return false;

        return true;
    }
};