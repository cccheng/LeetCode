class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        unordered_map<int,bool> inside;

        int i = 0, j = 0;
        while (i < pushed.size() || j < popped.size()) {
            if (i < pushed.size() && j < popped.size() && popped[j] == pushed[i]) {
                i++;
                j++;
            } else if (!stack.empty() && j < popped.size() && popped[j] == stack.top()) {
                stack.pop();
                j++;
            } else if (i < pushed.size()) {
                stack.push(pushed[i]);
                i++;
            } else {
                return false;
            }
        }

        return i == pushed.size() && j == popped.size();
    }
};
