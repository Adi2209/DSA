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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        bool flag=false;
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                
                if(frontNode==NULL){
                    flag=true;
                }
                else{
                    if(flag==true){
                        return false;
                    }
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
            }
        }
        return true;
    }
};