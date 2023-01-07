class TopVotedCandidate {
private:
    map<int, int> timeMap;
    unordered_map<int, int> countMap;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int winner = persons[0];
        timeMap[times[0]] = winner;
        int maxVote = 1;
        countMap[persons[0]] = 1;
        for (int i=1; i<times.size(); ++i) {
            countMap[persons[i]] ++;
            if (countMap[persons[i]] >= maxVote) {
                maxVote = countMap[persons[i]];
                winner = persons[i];
            }
            timeMap[times[i]] = winner;
        }
    }
    
    int q(int t) {
        auto it = timeMap.upper_bound(t);
        it --;
        return it->second;
    }


};