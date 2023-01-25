class BrowserHistory {
public:
    vector<string> history;
    int ptr=0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    void visit(string url) {
        ptr++;
        if(ptr<=history.size()-1){
            history[ptr]=url;
            history.resize(ptr+1);
        }
        else history.push_back(url);
    }
    
    string back(int steps) {
        ptr-=steps;
        if(ptr<0) ptr=0;
        return history[ptr];
    }
    
    string forward(int steps) {
        ptr+=steps;
        if(ptr>=history.size()-1){
            ptr=history.size()-1;
        }
        return history[ptr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */