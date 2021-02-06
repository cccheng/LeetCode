class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        deque<pair<int, int>> stack;

        sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) -> bool {
                return a[0] < b[0];
            });

        for (auto itv : intervals) {
            int begin = itv[0];
            int end = itv[1];

            while (!stack.empty()) {
                auto top = stack.back();
                if (begin <= top.first || begin <= top.second) {
                    stack.pop_back();
                    begin = min(top.first, begin);
                    end = max(top.second, end);
                } else {
                    break;
                }
            }
            stack.push_back(make_pair(begin, end));
        }

        vector<vector<int>> result;
        for (auto itv : stack)
            result.push_back({itv.first, itv.second});

        return result;
    }
};
