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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
           TreeNode* node= work_symmetric( root1, root2);
            return node;
    }
        
        
       TreeNode* work_symmetric(TreeNode* root1, TreeNode* root2)
        {
                if(root1==NULL && root2==NULL)
                {
                        return NULL;
                }
                if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL)
                {
                        return root1==NULL?root2:root1;
                }
               
               root1->right=work_symmetric(root1->right,root2->right);
               root1->left=work_symmetric(root1->left,root2->left);
                root1->val+=root2->val;
               return root1;
        }
};