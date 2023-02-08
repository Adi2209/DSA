class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> input;
    stack<int> output;
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ans=0;
        if(!output.empty()){
          ans=output.top();
          output.pop();  
        } 
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            ans=output.top();
            output.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans=0;
        if(!output.empty()){
          ans=output.top();
          // output.pop();  
        } 
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            ans=output.top();
            // output.pop();
        }
        return ans;
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */