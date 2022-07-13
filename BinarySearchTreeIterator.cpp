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
private:
    void partialInorder(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        partialInorder(top->right);
        return top->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */