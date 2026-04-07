//最小栈(双栈)
//大于最小值则压入最小值，小于等于则压入该数
class MinStack {
    ::stack<int> stack;
    ::stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        stack.push(val);
        min_stack.push(min(min_stack.top(),val));
    }
    
    void pop() {
        stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};