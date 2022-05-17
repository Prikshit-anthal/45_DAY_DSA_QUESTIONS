class Solution
{
    vector<string> v;

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s;
        if (root != NULL)
        {
            s += (to_string(root->val));
            if (root->left != NULL)
                preorder(root->left, s);
            if (root->right != NULL)
                preorder(root->right, s);
            if (root->left == NULL && root->right == NULL)
                v.push_back(s);
        }
        return v;
    }
    void preorder(TreeNode *root, string s)
    {
        if (root == NULL)
            return;

        s += ("->" + to_string(root->val));
        if (root->right == NULL && root->left == NULL)
        {
            v.push_back(s);
            return;
        }
        preorder(root->right, s);
        preorder(root->left, s);
    }
};