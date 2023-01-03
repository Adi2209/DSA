class Solution {
private:
    bool isOperator(string &ch){
        return ch=="+" || ch=="-" || ch=="/" || ch=="*";
    }
    long long doOperation(long long &op1,long long &op2, string &operation){
        if(operation=="+"){
            return op2+=op1;
        }
        else if(operation=="-"){
            return op2-=op1;
        }
        else if(operation=="*"){
            return op2*=op1;
        }
        else if(operation=="/"){
            return op2/=op1;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        //the brute force will be to use a stack data structure 
        //but we will try to use the vector tokens 
        long long top=0;
        
        for(auto &it:tokens){
            if(!isOperator(it)){
                tokens[top]=it;
                top++;
            }
            else{
                top--;
                long long ele1=stoll(tokens[top]);
                top--;
                long long ele2=stoll(tokens[top]);
                long long result=doOperation(ele1,ele2,it);
                tokens[top]=to_string(result);
                top++;
            }
        }
        long long finalAns=stoll(tokens[0]);
        return finalAns;
    }
};