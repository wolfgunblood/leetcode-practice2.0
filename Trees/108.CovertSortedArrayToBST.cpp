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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0)
        return new TreeNode();

        return helper(nums,0,nums.size()-1); 
    }

    TreeNode* helper(vector<int>& nums,int leftBound,int rightBound){

        if(leftBound > rightBound) return NULL;

        int pivot = leftBound + (rightBound - leftBound)/2;

        TreeNode* node = new TreeNode(nums[pivot]);
        node->left = helper(nums,leftBound,pivot-1);
        node->right = helper(nums,pivot+1,rightBound);

        return node;
    }
};