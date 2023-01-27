class Solution {
private:
    void getCount(int &countG,int& countM,int &countP,int& lastG,int& lastP,int &lastM,vector<string>& garbage){
        
        for(int ind=0;ind<garbage.size();ind++){
            string it=garbage[ind];
            for(auto c:it){
                if(c=='P') countP++,lastP=ind;
                if(c=='G') countG++,lastG=ind;
                if(c=='M') countM++,lastM=ind;
            }
        }
    }
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int countG=0,countM=0,countP=0;
        int lastG=0,lastM=0,lastP=0;
        
        vector<int> prefixTime(travel.size()+1);
        
        for(int ind=1;ind<prefixTime.size();ind++)
            prefixTime[ind]=travel[ind-1]+prefixTime[ind-1];
        
        getCount(countG,countM,countP,lastG,lastP,lastM,garbage);
        int minTime=0;
        if(countM){
            minTime+=(countM+ prefixTime[lastM]);
        }
        if(countP){
            minTime+=(countP+ prefixTime[lastP]);
        }
        if(countG){
            minTime+=(countG+ prefixTime[lastG]);
        }
        return minTime;
    }
};