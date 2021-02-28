class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> index = {
            {"type", 0},
            {"color", 1},
            {"name", 2}
        };

        int x = index[ruleKey];
        int count = 0;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i][x] == ruleValue)
                count++;
        }

        return count;
    }
};

// v2. count_if
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> index = {
            {"type", 0},
            {"color", 1},
            {"name", 2}
        };

        int x = index[ruleKey];
        return count_if(items.begin(), items.end(),
                        [&](auto& vec) { return ruleValue == vec[x]; });
    }
};
