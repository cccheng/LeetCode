class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> table(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i < table.size(); ++i) {
            for (int j = 1; j < table[i].size(); ++j) {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
                if (text1[i - 1] == text2[j - 1])
                    table[i][j] = max(table[i][j], table[i-1][j-1] + 1);
            }
        }

        return table[text1.size()][text2.size()]; //.back().back();
    }
};
