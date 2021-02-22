class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int> count(d.size());

        for (auto c : s) {
            for (int i = 0; i < d.size(); i++) {
                if (count[i] < d[i].size() && d[i][count[i]] == c)
                    count[i]++;
            }
        }

        string empty;
        string* result = &empty;
        for (int i = 0; i < d.size(); ++i)
            if (count[i] == d[i].size()) {
                if (d[i].size() > result->size())
                    result = &d[i];
                if (d[i].size() == result->size() && d[i] < *result)
                    result = &d[i];
            }

        return *result;
    }
};
