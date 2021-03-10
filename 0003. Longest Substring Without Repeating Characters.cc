class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;

        int cur = 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!last.count(s[i])) {
                cur++;
            } else {
                cur = min(cur + 1, i - last[s[i]]);
            }
            last[s[i]] = i;
            result = max(result, cur);
        }

        return result;
    }
};
