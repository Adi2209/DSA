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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0,maxSum=-1e9,level=0,ans=0;
        
        while(!q.empty()){
            sum=0;
            level++;
            int size=q.size();
            for(int ind=0;ind<size;ind++){
                TreeNode* frontNode=q.front();
                q.pop();
                sum+=frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            if(sum>maxSum){
                maxSum=sum;
                ans=level;
            }
        }
        return ans;
    }
};