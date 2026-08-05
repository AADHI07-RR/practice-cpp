class MinStack {
public:
    vector<pair<int,int>> s;
    MinStack() {
        
    
    }
    
    void push(int value) {
        if(!s.empty()) {
            int Min=min(value,s.back().second);
        s.push_back(make_pair(value,Min));
        }
        else{
            s.push_back({value,value});
        }
        
    }
    
    void pop() {
       
             s.pop_back();
        
    }
    
    int top() {
       
            return s.back().first;
        
    }
    
    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */