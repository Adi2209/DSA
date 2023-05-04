class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq, dq;
        vector<int> vis(n);
        int rcnt = 0, dcnt = 0, rskip = 0, dskip = 0;
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R') rcnt++;
            else dcnt++;
        }
        int index = 0;
        while(rcnt and dcnt){
            if(senate[index] == 'R'){
                if(rskip) rskip--, senate[index] = 'X';
                else dskip++, dcnt--;
            }
            else if(senate[index] == 'D'){
                if(dskip) dskip--, senate[index] = 'X';
                else rskip++, rcnt--;
            }
            index = (index + 1)%n;
        }
        return rcnt ? "Radiant" : "Dire";
    }
};