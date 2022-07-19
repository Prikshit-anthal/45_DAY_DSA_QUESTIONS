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
    vector<int> ans;

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode *, TreeNode *> m; // child parent pair to use dfs up parent

        m[root] = NULL;
        setParent(root, m);

        // now dfs
        dfs_helper(target, NULL, m, k); // dekh NULL bejra coz assuming target se graph bnra
        // cout<<m[target]->val<<endl;
        return ans;
    }

    void setParent(TreeNode *root, map<TreeNode *, TreeNode *> &m)
    {
        if (root->right != NULL)
        {
            m[root->right] = root;
            setParent(root->right, m);
        }
        if (root->left != NULL)
        {
            m[root->left] = root;
            setParent(root->left, m);
        }
    }
    void dfs_helper(TreeNode *root, TreeNode *parent, map<TreeNode *, TreeNode *> &m, int k)
    {
        // base
        if (root == NULL)
            return;
        if (k == 0)
            ans.push_back(root->val);

        // left
        if (parent != root->left)
            dfs_helper(root->left, root, m, k - 1);

        // right
        if (parent != root->right)
            dfs_helper(root->right, root, m, k - 1);

        // parent
        if (parent != m[root])
            dfs_helper(m[root], root, m, k - 1);
    }
};