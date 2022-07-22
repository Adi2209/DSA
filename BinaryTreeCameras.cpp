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
private:
    //2->node has a camera
    //1-> node is covered with a camera
    //0->no camera is covering this node
    int dfs(TreeNode* root,int& cam){
        //base case
        if(root==NULL) return 1;//case for child node of the leaf node...it is covered by the cmaera because we will place the cameras just above the leaf nodes
        int left=dfs(root->left,cam);
        int right=dfs(root->right,cam);
        if(left==0 || right==0){
            cam++;
            return 2;
        }
        else if(left==2 || right==2) return 1;
        else return 0;
        
    }
public:
    int minCameraCover(TreeNode* root) {
        int cam=0;
        //dfs function will return 0,(1,2)-> 1or 2 means that the root is covered by a cam and 0 means that the root is not covered, hence we will have to add a cam
        return dfs(root,cam)==0? cam+1:cam;
        
    }
};