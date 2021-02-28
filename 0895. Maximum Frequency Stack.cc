class FreqStack {
public:
    map<int, stack<int>> freq_stack;
    map<int, int> freq;
    int max_freq;

    FreqStack() : max_freq(0) {

    }

    void push(int x) {
        freq[x]++;
        max_freq = max(max_freq, freq[x]);
        freq_stack[freq[x]].push(x);
    }

    int pop() {
        while (freq_stack[max_freq].empty()) {
            max_freq--;
        }

        int ret = freq_stack[max_freq].top();
        freq_stack[max_freq].pop();
        freq[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
