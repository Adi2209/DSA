class Solution {
public:
    int countOdds(int low, int high) {
        int oddCnt=0;
        while(low<=high){
            if(low%2!=0) oddCnt++;
            low++;
        }
        return oddCnt;
    }
};