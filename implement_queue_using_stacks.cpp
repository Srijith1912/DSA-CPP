class MyQueue {
vector<int> instack;
vector<int> outstack;

void transfer(){
    while(!instack.empty()){
        outstack.push_back(instack.back());
        instack.pop_back();
    }
}

public:
    MyQueue() {
        
    }
    
    void push(int x) {

        instack.push_back(x);
    }
    
    int pop() {

        if (outstack.empty()){
            transfer();
            }

        int res = outstack.back();
        outstack.pop_back();
        return res;
    }
    
    int peek() {

        if (outstack.empty()){
            transfer();
            }

        int res = outstack.back();
        return res;
    }
    
    bool empty() {
        
        return instack.empty() && outstack.empty();
        
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