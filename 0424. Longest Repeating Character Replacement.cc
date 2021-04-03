class Solution {
public:
    int characterReplacement(string s, int k) {
        int nr = s.size(), most;
        int left = 0, right = 0;
        int mx = right - left + 1;
        map<char,int> count;

        if (s.empty())
            return 0;

        for (right = 0; right < nr; ++right) {
            count[s[right]]++;

            most = max_element(count.begin(), count.end(),
                [](auto& a, auto& b) { return a.second < b.second; }
            )->second;

            while (right - left + 1 - most > k) {
                count[s[left]]--;
                left++;
            }
            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};
