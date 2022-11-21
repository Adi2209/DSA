class Solution {
public:
    bool check_constraint (int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    bool check_boundary (int i, int j, int m, int n){        
        return (i == 0 || i == m-1 || j == 0 || j == n-1);
    }
	
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int level = 0, m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis (m, vector<bool>(n,0));
        q.push (entrance);
        
        vis[entrance[0]][entrance[1]] = 1;
        
        while (!q.empty ()){
            int len = q.size();
            
            for (int i = 0; i < len; i++){
                auto x = q.front ()[0];
                auto y = q.front ()[1];
                q.pop ();
                
				//go down
                if (check_constraint (x+1,y,m,n) && !vis[x+1][y] && maze[x+1][y] == '.'){
                    if (check_boundary(x+1,y,m,n)) return level+1;
                    
                    vis[x+1][y] = 1;
                    q.push ({x+1,y});
                }
                
				// go up
                if (check_constraint (x-1,y,m,n) && !vis[x-1][y]&& maze[x-1][y] == '.'){
                    if (check_boundary(x-1,y, m,n)) return level+1;
                    
                    vis[x-1][y] = 1;
                    q.push ({x-1,y});
                }
                
				//go right
                if (check_constraint (x,y+1,m,n)  && !vis[x][y+1] && maze[x][y+1] == '.'){
                    if (check_boundary(x,y+1,m,n)) return level+1;
                    
                    vis[x][y+1] = 1;
                    q.push ({x,y+1});
                }
                
				//go left
                if (check_constraint (x,y-1,m,n)  && !vis[x][y-1] && maze[x][y-1] == '.'){
                    if (check_boundary(x,y-1,m,n))  return level+1;
                    
                    vis[x][y-1] = 1;
                    q.push ({x,y-1});
                }
            }
            
            level++;
        }
        
        return -1;
    }
};