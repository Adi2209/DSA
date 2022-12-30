class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        int moves=0;
        while(sum<target){
            moves++;
            sum+=moves;
        }
        if(sum==target) return moves;
        
        int diff=sum-target;
        if(diff%2==0)
            return moves;
        else{
            if(moves%2==0) return moves+1;
            else
                return moves+2;
        }
        return -1;
    }
};