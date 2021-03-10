class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        auto is_palindrome = [](string_view str) -> bool {
            for (int l=0, r=str.size()-1; l < r; l++, r--)
                if (str[l] != str[r])
                    return false;
            return true;
        };

        function<void(int,vector<string>)> dfs = [&](int offset, vector<string> items) {
            if (offset == s.size())
                result.push_back(items);
            for (int end = offset+1; end <= s.size(); ++end) {
                if (is_palindrome(s.substr(offset, end-offset))) {
                    items.push_back(s.substr(offset, end-offset));
                    dfs(end, items);
                    items.pop_back();
                }
            }
        };

        dfs(0, {});

        return result;
    }
};
