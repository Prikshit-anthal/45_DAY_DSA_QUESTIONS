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
    vector<int> arr;

public:
    int getMinimumDifference(TreeNode *root)
    {
        // inorder se sorted array hmesha BST
        inorder(root);
        int min = 1e9;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) < min)
                min = abs(arr[i] - arr[i - 1]);
        }
        return min;
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        arr.push_back(root->val);

        inorder(root->right);
    }
};