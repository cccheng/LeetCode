class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> pack;

        if (s.empty())
            return s;

        pack.push_back({s[0], 1});
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == pack.back().first)
                (&pack.back())->second++;
            else
                pack.push_back({s[i], 1});
        }

        vector<pair<char,int>> stack;
        for (auto& p : pack) {
            if (p.second == k) {
                continue;
            } else if (!stack.empty() && stack.back().first == p.first) {
                int sum = stack.back().second + p.second;
                if (sum >= k) {
                    if (sum % k == 0)
                        stack.pop_back();
                    else
                        (&stack.back())->second = sum % k;
                } else {
                    (&stack.back())->second += p.second;
                }
            } else {
                stack.push_back(p);
            }
        }

        string result;
        for (auto p : stack) {
            for (int i = 0; i < p.second; ++i)
                result.push_back(p.first);
        }

        return result;
    }
};
