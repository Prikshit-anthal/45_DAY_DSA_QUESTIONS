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
class BSTIterator
{
    TreeNode *start;
    queue<int> q;

public:
    BSTIterator(TreeNode *root)
    {
        start = root;
        inorder(root);
    }

    int next()
    {
        int curr = q.front();
        q.pop();
        return curr;
    }

    bool hasNext()
    {
        return !q.empty();
    }

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        q.push(root->val);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */