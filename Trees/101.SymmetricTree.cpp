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
    bool dfs(TreeNode* leftTree,TreeNode* rightTree){

        if(leftTree == NULL && rightTree == NULL) return true;
        if(leftTree == NULL || rightTree == NULL) return false;

        return (leftTree->val == rightTree->val) && dfs(leftTree->left,rightTree->right) && dfs(leftTree->right,rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {

        return dfs(root,root);    
    }
};