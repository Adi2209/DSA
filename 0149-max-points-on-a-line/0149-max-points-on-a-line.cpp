class Solution {
private:
    long double getSlope(long double dy,long double dx){
        double slope=(double) dy/dx;
        return slope;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        //we will calculate slope and push into a map
        
        int n=points.size();
        int yAxis=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            unordered_map<double, int> mp;
            int yAxis = 0;
            for(int j=i+1; j<n; j++){
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if(dx==0){
                    yAxis++;
                }else{
                    double slope = getSlope(dy,dx);
                    mp[slope]++;
                }
            }
            for(auto &m : mp){
                cnt = max(cnt, m.second);
            }
            cnt = max(cnt, yAxis);
        }
        return cnt+1;
    }
	
};