class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int> >st;
    vector<int> vec;
    
    
    int next(int price) {
        vec.push_back(price);
        int days=1;
        while(!st.empty() && st.top().first<=price){
            days+=st.top().second;
            st.pop();
        } 
        st.push({price,days});
        return st.top().second;     
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */