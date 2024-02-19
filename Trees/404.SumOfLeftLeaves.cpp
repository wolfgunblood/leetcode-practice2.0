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
    
    int dfs(TreeNode* root,bool lFlag){

        if(root == NULL) return 0;

        if(lFlag && root->left == NULL && root->right == NULL){
            
            return root->val;
        }

        int lval = dfs(root->left,true);
        int rval = dfs(root->right,false);

        return lval + rval;

    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = dfs(root,false);

        return sum;
    }
};