class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //the brute force will be to use a stack and iterate from the fron for the operators 
        //the optimsed soln. will be to  use the tokens vector as the stack just like below.
        
        long long top=0;//top will be the iterator for the vector
        
        for(auto t:tokens){
            if(t != "+" && t != "-" && t != "*" && t != "/"){
                tokens[top]=t;
                top++;
            }
            else{
                top--;
                long long ele1=stoll(tokens[top]);
                top--;
                long long ele2=stoll(tokens[top]);
    
                
                if(t=="+") ele2+=ele1;
                else if(t=="-") ele2-=ele1;
                else if(t=="*") ele2*=ele1;
                else if(t=="/") ele2/=ele1;
                
                tokens[top]=to_string(ele2);
                top++;
            }
        }
        return stoll(tokens[0]);
    }
};