/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* getTree(string& data,int& ind){
        if(ind==data.length())
            return NULL;
        
        string str;
        while(ind<data.length() && data[ind]!=',')
        {
            str+=data[ind++];
        }
        ind++;
        if(str=="#")
            return NULL;
        int val=stoi(str);
        TreeNode* root= new TreeNode(val);
        root->left=getTree(data,ind);
        root->right=getTree(data,ind);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "#,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right) ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind=0;
        return getTree(data,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;