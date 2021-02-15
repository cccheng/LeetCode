class MinStack {
    stack<int> data;
    stack<int> minimum;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data.push(x);
        if (minimum.empty())
            minimum.push(x);
        else
            minimum.push(min(x, minimum.top()));
    }

    void pop() {
        data.pop();
        minimum.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minimum.top();
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
