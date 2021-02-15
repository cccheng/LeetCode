class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows >= 1)
            result.push_back({1});
        if (numRows >= 2)
            result.push_back({1,1});

        for (auto i = 2; i < numRows; ++i) {
            vector<int> tmp;
            tmp.push_back(1);
            for (auto j = 1; j < i; ++j)
                tmp.push_back(result[i-1][j-1] + result[i-1][j]);
            tmp.push_back(1);
            result.push_back(tmp);
        }

        return result;
    }
};
