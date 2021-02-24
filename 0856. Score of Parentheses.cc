class Solution {
public:

    int score(string& str, int begin, int end) {
        if (end - begin <= 2)
            return 1;

        int balance = 0;
        for (int i = begin; i < end - 1; ++i) {
            if (str[i] == '(')
                balance--;
            else
                balance++;

            if (balance == 0)
                return score(str, begin, i) + score(str, i+1, end);
        }

        return 2 * score(str, begin + 1, end - 1);
    }

    int scoreOfParentheses(string S) {
        return score(S, 0, S.size());
    }
};

// v2
class Solution {
public:
    int scoreOfParentheses(string S) {
        int cur = 0;
        stack<int> stack;

        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                stack.push(cur);
                cur = 0;
            } else {
                cur = max(1, 2 * cur) + stack.top();
                stack.pop();
            }
        }

        return cur;
    }
};
