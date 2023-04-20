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
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans=0;
        
        if(root==NULL){
            return ans;
        }
        
        queue<pair<TreeNode*,long long> >q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            
            int size=q.size();
            //to save overflow 
            long long mMin=q.front().second;
 
            int first,last;
           
            for(int i=0;i<size;i++){
             long long curr_id=q.front().second-mMin;
          
                TreeNode* frontNode=q.front().first;
                q.pop();
                
                 if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                
                if(frontNode->left)
                    q.push({frontNode->left,curr_id*2+1});
                if(frontNode->right)
                    q.push({frontNode->right,curr_id*2+2});        
                
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};