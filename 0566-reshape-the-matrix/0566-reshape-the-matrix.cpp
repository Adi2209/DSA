class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans;
        int nr=0;
        vector<int> nc;
        int m=0,k=0;
        if(r*c!=mat.size()* mat[0].size())
        {
            return mat;
        }
        else
        {
            for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                nc.push_back(mat[m][k]);
                if(k<mat[0].size())
                {
                    k++;
                }
                if((k==mat[0].size() && m<mat.size()))
                {
                    m++;
                    k=0;
                }
                if(m==mat.size())
                {
                    m=0;
                    k=0;
                    break;
                }
            }
            ans.push_back(nc);
            nc.clear();
        }
        }
        
        return ans;
    }
};