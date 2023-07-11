/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*,TreeNode*> trackParent;
        map<TreeNode*,bool> isVisited;
        
        queue<TreeNode*> q;
        //first bfs to track and store all parent nodes ..
        q.push(root);
        while(!q.empty()){
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                
                if(frontNode->left){
                    trackParent[frontNode->left]=frontNode;
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    trackParent[frontNode->right]=frontNode;
                    q.push(frontNode->right);
                }       
            }
        }
        //now for 2nd bfs
        
        q.push(target);
        isVisited[target]=true;//marking true for all the visited nodes starting from the target
        int distance=0;
        while(!q.empty()){
            
            int size=q.size();
                if(distance==k){
                    break;
                }
                else{
                    distance++;
                }
            
                
                for(int i=0;i<size;i++){
                    
                    TreeNode* frontNode=q.front();
                    q.pop();
                    
                    if(frontNode->left && isVisited[frontNode->left]==false){
                        q.push(frontNode->left);
                        isVisited[frontNode->left]=true;
                    }
                    if(frontNode->right && isVisited[frontNode->right]==false){
                        q.push(frontNode->right);
                        isVisited[frontNode->right]=true;
                    }
                    if(trackParent[frontNode] && isVisited[trackParent[frontNode]]==false){
                        q.push(trackParent[frontNode]);
                        isVisited[trackParent[frontNode]]=true;
                    }
                }  
            }
        //you will reach here after breaking in line 47 as distance==target is achieved
            vector<int> ans;
            while(!q.empty()){
                
                TreeNode* frontNode=q.front();
                    q.pop();
                ans.push_back(frontNode->val);
                
            }
        
        return ans;
        
    }
};