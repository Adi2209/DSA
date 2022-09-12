class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //  Declaring initial score
        int score = 0;
        // Keeping the track of maximum score as found till
        int maxScore = 0;
        // Sorting the tokens vector to apply the greedy approach
        sort(tokens.begin(), tokens.end());
        // Taking high value as size of the vector initially
        int high = tokens.size();
        for(int i=0;i<high;i++){
            // Checking if score is 0 and the tokens[i] is greater than current power
            // Then maximum score will be the current max
            if(score == 0 and tokens[i] > power) return maxScore;
            // If the current tokens[i] is less than the power we are having then we
            // can simply decrement the power and increment the score to +1
            if(tokens[i] <= power){
                power -= tokens[i];
                score += 1;
            }
            else{
                // If the tokens[i] > power and score > 0 then we can loose one score
                // and add the highest power to our current power
                if(score > 0){
                    power += tokens[high-1];
                    high -= 1;
                    score -= 1;
                    i -= 1;
                }
            }
            // Keeping the track of maximum score
            maxScore = max(score, maxScore);
        }
        return maxScore;
    }
};
