class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        bool flag=false;
        
        while(s.size()>1){
            //in case of odd
            if(s.back()=='1'){
                steps++;
                flag=true;
                for(int r=s.size()-1;r>=0;r--){
                    if(s[r]=='0'){
                        s[r]='1';
                        flag=false;
                        break;
                    }
                    else{
                        s[r]='0';
                    }
                }
            }
            else{
                //in case of even->left shift
                s.pop_back();
                steps++;
            }
        }
        if(flag){
            steps++;
            return steps;
        }
        return steps;
    }
};