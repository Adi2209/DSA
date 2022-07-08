class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //the brute force will be to use a stack and iterate from the fron for the operators 
        //the optimsed soln. will be to  use the tokens vector as the stack just like below.
        
        int top=0;//top will be the iterator for the vector
        
        for(auto t:tokens){
            if(t != "+" && t != "-" && t != "*" && t != "/"){
                tokens[top]=t;
                top++;
            }
            else{
                top--;
                int ele1=stoi(tokens[top]);
                top--;
                int ele2=stoi(tokens[top]);
    
                
                if(t=="+") ele2+=ele1;
                else if(t=="-") ele2-=ele1;
                else if(t=="*") ele2*=ele1;
                else if(t=="/") ele2/=ele1;
                
                tokens[top]=to_string(ele2);
                top++;
            }
        }
        return stoi(tokens[0]);
    }
};