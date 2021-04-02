class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size() + 1);
        memo[0] = true;

        for (int i = 0; i < s.size(); ++i) {
            if (!memo[i])
                continue;
            for (auto& w : wordDict) {
                if (i + w.size() <= s.size() && w == s.substr(i, w.size()))
                    memo[i + w.size()] = true;
            }
        }

        return memo.back();
    }
};
