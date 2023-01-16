class Solution {
private:
    void getPrefixSum(vector<vector<int>>& temp,int n){
        
        for(int ind=0;ind<n;ind++){
            for(int idx=1;idx<n;idx++){
                temp[ind][idx]+= temp[ind][idx-1];
            }
        }
    }
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> temp(n, vector<int>(n,0));
        int size=queries.size();
        for(int i=0; i<size; i++){
            int toprow= queries[i][0];
            int leftcol= queries[i][1];
            int bottomrow= queries[i][2];
            int rightcol= queries[i][3];
            
            for(int j=toprow; j<=bottomrow; j++){
                temp[j][leftcol] +=1;
                if( rightcol<n-1)
                    temp[j][rightcol+1] +=-1;
            }
        }
         
        getPrefixSum(temp,n);
    

        return temp;
    }
};