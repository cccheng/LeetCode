class Solution {
public:
    bool isValid(string s) {
        stack<char> open_bracket;

        for (auto c : s) {
            if (c == '}') {
                if (!open_bracket.empty() && open_bracket.top() == '{')
                    open_bracket.pop();
                else
                    return false;
            } else if (c == ')') {
                if (!open_bracket.empty() && open_bracket.top() == '(')
                    open_bracket.pop();
                else
                    return false;
            } else if (c == ']') {
                if (!open_bracket.empty() && open_bracket.top() == '[')
                    open_bracket.pop();
                else
                    return false;
            } else
                open_bracket.push(c);
        }

        if (open_bracket.empty())
            return true;
        return false;
    }
};
