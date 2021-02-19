class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,char>> match;

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                match.push({i, '('});
            } else if (s[i] == ')') {
                if (!match.empty() && match.top().second == '(')
                    match.pop();
                else
                    match.push({i, ')'});
            }
        }

        vector<bool> dropped(s.size());
        while (!match.empty()) {
            dropped[match.top().first] = true;
            match.pop();
        }

        string result;
        for (auto i = 0; i < s.size(); ++i)
            if (!dropped[i])
                result.push_back(s[i]);

        return result;
    }
};
