class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;

        for (auto s : tokens) {
            if (string("+-*/").find(s) == string::npos) {
                stk.push(s);
            } else {
                string op1 = stk.top(); stk.pop();
                string op2 = stk.top(); stk.pop();

                if (s == "+")
                    stk.push(to_string(stoi(op2) + stoi(op1)));
                else if (s == "-")
                    stk.push(to_string(stoi(op2) - stoi(op1)));
                else if (s == "*")
                    stk.push(to_string(stoi(op2) * stoi(op1)));
                else if (s == "/")
                    stk.push(to_string(stoi(op2) / stoi(op1)));
            }
        }

        return stoi(stk.top());
    }
};
