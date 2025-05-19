class MinStack {

    vector<pair<int, int>> stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {

        if(stack.empty()){
            stack.push_back({val, val});
        }
        else{
            int currentmin = min(val, stack.back().second);
            stack.push_back({val, currentmin});
        }
        
    }
    
    void pop() {
        
        if (!stack.empty()){
            stack.pop_back();
        }
    }
    
    int top() {
        
        int t;

        if (!stack.empty()){
            t = stack.back().first;
        }
        return t;
    }
    
    int getMin() {
        
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */