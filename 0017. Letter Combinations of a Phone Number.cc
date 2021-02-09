class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> result;
        string str(digits.size(), ' ');

        function<void(int)> dfs = [&](int offset) -> void {
            if (offset == digits.size()) {
                result.push_back(str);
                return;
            }

            for (auto c : mp[digits[offset]]) {
                str[offset] = c;
                dfs(offset + 1);
            }
        };

        if (!digits.empty())
            dfs(0);

        return result;
    }
};
