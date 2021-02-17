class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        size_t min_len = numeric_limits<size_t>::max();

        if (strs.empty())
            return "";

        for (auto s : strs)
            min_len = min(min_len, s.size());
        for (int i = 0; i < min_len; ++i) {
            for (int s = 0; s < strs.size(); ++s) {
                if (strs[0][i] != strs[s][i])
                    goto out;
            }
            prefix.push_back(strs[0][i]);
        }

out:
        return prefix;
    }
};
