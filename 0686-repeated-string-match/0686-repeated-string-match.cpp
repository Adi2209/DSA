class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int count=1;
        int maxRepeat=b.size()/a.size();
        for(int ind=0;ind<maxRepeat+2;ind++){
            // a.find(b) != string::npos
            int found=a.find(b);
            if(found!=-1) return count;
            else{
                a+=temp;
                count++;
            }
        }
        return -1;
    }
};