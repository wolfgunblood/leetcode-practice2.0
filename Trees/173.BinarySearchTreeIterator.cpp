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
class BSTIterator {
public:
    TreeNode* c = new TreeNode();
    stack<int> stk;

    void inorder(TreeNode* root){

        if(root == NULL) return ;

        if(root->right)inorder(root->right);
        c=root;
        stk.push(root->val);
        if(root->left) inorder(root->left);

    }

    BSTIterator(TreeNode* root) {
        inorder(root);    
    }
    
    int next() {
        
        int n = stk.top();
        stk.pop();
        return n;
    }
    
    bool hasNext() {
        
        if(stk.size() > 0) return true;

        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */