class Solution {
public:
 
    vector<string> findRelativeRanks(vector<int>& score) {
        
    priority_queue<pair<int,int>>  pq;
        
    vector<string> result(score.size(),"");
    
    for(int i=0; i<score.size() ; i++){
        pq.push({score[i],i});
    }
    
    for(int i=0; i<score.size() ; i++){
        
        if(i==0){
            result[pq.top().second]="Gold Medal";
            pq.pop();
        }else if(i==1){
            result[pq.top().second]="Silver Medal";
             pq.pop();
        }else if(i==2){
            result[pq.top().second]="Bronze Medal";
             pq.pop();
        }else{
            result[pq.top().second]=to_string(i+1);
            pq.pop();
        }
    }
    
    return result;
    
}
};