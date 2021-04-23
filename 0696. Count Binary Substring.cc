class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> compact;

        int count = 1;
        auto prev = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == prev) {
                count++;
            } else {
                compact.push_back(count);
                prev = s[i];
                count = 1;
            }
        }
        compact.push_back(count);

        int result = 0;
        for (int i = 1; i < compact.size(); ++i) {
            result += min(compact[i-1], compact[i]);
        }

        return result;
    }
};
