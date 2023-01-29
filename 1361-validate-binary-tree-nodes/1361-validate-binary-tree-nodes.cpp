class Solution {
private:
    int totalNodes(vector<int>& leftChild,vector<int>& rightChild,int root){
        //base case
        if (root == -1) return 0;
        int leftCount=totalNodes(leftChild, rightChild, leftChild[root]);
        int rightCount=totalNodes(leftChild, rightChild, rightChild[root]);
        return 1 +leftCount + rightCount;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        //checking if any node has more than 1 parent 
        vector<int> countParent(n);
        for(int ind=0;ind<n;ind++){
            // countParent[rightChild[ind]]++;
            // countParent[leftChild[ind]]++;
            if((leftChild[ind]>=0 && ++countParent[leftChild[ind]]>1) || (rightChild[ind]>=0 && ++countParent[rightChild[ind]] >1 )) return false;
        }
        //if more than one root exists
        int root=-1;
        for(int ind=0;ind<n;ind++){
            if(countParent[ind]==0){
                if(root==-1) root=ind;
                else return false;
            }
        }
        //now calculating the total Nodes if == to n
        
        if(totalNodes(leftChild,rightChild,root)==n) return true;
        return false;
        
    }
};