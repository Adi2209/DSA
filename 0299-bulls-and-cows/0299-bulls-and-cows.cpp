class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mpGuess;
        unordered_map<char,int> mpSecret;
        int bulls=0,cows=0;
        int n=secret.size();
        for(int ind=0;ind<n;ind++){
            if(secret[ind]==guess[ind]) bulls++;
            else{
                mpGuess[guess[ind]]++;
                mpSecret[secret[ind]]++;
            }
        }
        for(auto &it: mpSecret){
            if(mpGuess.count(it.first)>0){
                cows+=min(it.second,mpGuess[it.first]);
            }
        }
       
        return to_string(bulls) + "A" +to_string(cows) + "B";
    }
};