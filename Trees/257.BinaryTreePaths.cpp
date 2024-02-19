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
    void dfs(TreeNode* root, vector<string> &res,string curr){

        if(root->left == NULL && root->right == NULL){ 

            curr += to_string(root->val);
            res.push_back(curr);
            curr.pop_back();
            return ;
        }

        curr += to_string(root->val);
        curr += "->";

        if(root->left != NULL) dfs(root->left,res,curr);
        if(root->right != NULL) dfs(root->right,res,curr);

        curr.pop_back();
        curr.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        string curr;
        dfs(root,res,curr);
        return res;

    }
};