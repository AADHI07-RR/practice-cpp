class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    
    }
    
    void push(int value) {
        if(!s.empty()) {
            int Min=min(value,s.top().second);
        s.push(make_pair(value,Min));
        }
        else{
            s.push({value,value});
        }
        
    }
    
    void pop() {
       
             s.pop();
        
    }
    
    int top() {
       
            return s.top().first;
        
    }
    
    int getMin() {
        return s.top().second;
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