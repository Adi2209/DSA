class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        // {diff,{row,col}}
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        vector<int> delRow{-1,0,1,0};
        vector<int> delCol{0,1,0,-1};
        
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow<n && nRow>=0 && nCol>=0 && nCol<m){
                    int newEffort=max(abs(heights[row][col]-heights[nRow][nCol]),diff);
                    if(newEffort<dist[nRow][nCol]){
                        dist[nRow][nCol]=newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }
        return 0;
    }
};