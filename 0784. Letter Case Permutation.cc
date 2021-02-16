class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;

        function<void(string,int)> dfs = [&](string str, int offset) -> void {
            while(offset < str.size() && !isalpha(str[offset]))
                offset++;

            if (offset >= str.size()) {
                result.push_back(str);
                return;
            }

            dfs(str, offset + 1);
            str[offset] ^= ' ';
            dfs(str, offset + 1);
        };

        dfs(S, 0);
        return result;
    }
};
