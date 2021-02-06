class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0], newInterval[1]});    
        sort(intervals.begin(), intervals.end(), 
             [](const auto& a, const auto& b) -> bool { return a[0] < b[0]; });
    
        deque<pair<int, int>> deque;
        for (auto i : intervals) {
            int begin = i[0];
            int end = i[1];
            
            while (!deque.empty() && deque.back().second >= begin) {
                begin = min(begin, deque.back().first);
                end = max(end, deque.back().second);
                deque.pop_back();
            }
            
            deque.push_back({begin, end});
        }
        
        vector<vector<int>> result;
        for (auto i : deque)
            result.push_back({i.first, i.second});
        return result;
    }
};
