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

// v2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             }
            );

        auto mergable = [](const auto& a, const auto& b) -> bool {
            if (a[0] <= b[0] && a[1] <= b[1] && b[0] <= a[1])
                return true;
            if (b[0] <= a[0] && b[1] <= a[1] && a[0] <= b[1])
                return true;
            if (a[0] <= b[0] && a[1] >= b[1])
                return true;
            if (b[0] <= a[0] && b[1] >= a[1])
                return true;
            return false;
        };

        auto merge = [](auto& a, const auto& b) -> void {
            a[0] = min(a[0], b[0]);
            a[1] = max(a[1], b[1]);
        };

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (mergable(result.back(), intervals[i]))
                merge(result.back(), intervals[i]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
