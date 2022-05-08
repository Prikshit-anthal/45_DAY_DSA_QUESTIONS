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
    int diameterOfBinaryTree(TreeNode* root) {
      vector<int>ans= start_from_root(root);
        cout<<ans[0]<<" "<<ans[1]<<endl;
        return ans[1];
    }
    
    
    //fn
    vector<int> start_from_root(TreeNode* root)
    {
        vector<int> left={-1,-1},right={-1,-1},ans(2,-1);//max_height,curr_best
        if(root->left==NULL && root->right==NULL)
        {
            ans[0]=0;
            ans[1]=0;
            return ans;
        }
        
        if(root->left!=NULL)
        left=start_from_root(root->left);
        if(root->right!=NULL)
        right=start_from_root(root->right);
        
                                if(left[0]>right[0])
                ans[0]=left[0]+1;
            else
                ans[0]=right[0]+1;
        
        if(left[0]+right[0]+2>left[1] && left[0]+right[0]+2>right[1])
        {
            ans[1]=(left[0]+right[0]+2);

        }
        else if(right[1]>left[1])
        {
            ans[1]=(right[1]);
        }
        else{
            ans[1]=(left[1]);
        }
        
        return ans;
        
    }
    
   
};