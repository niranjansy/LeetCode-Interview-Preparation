// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> S;
    stack<int> min;
    /** initialize your data structure here. */    
    MinStack() 
    {}
    
    void push(int x) {
        S.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }
    
    void pop() {
        int val = S.top();
        S.pop();
        if(val == min.top())
            min.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */