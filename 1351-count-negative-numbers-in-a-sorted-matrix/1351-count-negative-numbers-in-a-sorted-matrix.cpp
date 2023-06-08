
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cols=grid.size();
        int rows=grid[0].size();
		
        int rindex=0;
        int cindex=rows-1;
        int count=0;
        while(rindex<cols and cindex>=0)
        {
		
            if(grid[rindex][cindex]<0)
            {
                count+=(cols-rindex);
                cindex--;
            }
			//if it is positve then we know that all element in that vertical part is negative so we move 
			//to next row.
            else
            {
                rindex++;
            }
            
        }
        return count;
         
        
    }
	
};