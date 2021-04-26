class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int ans = 0;
        while (ans+1 < heights.size()) {
            int diff = heights[ans+1] - heights[ans];
            if (diff > 0)
                min_heap.push(diff);
            if (min_heap.size() > ladders) {
                bricks -= min_heap.top();
                min_heap.pop();
            }
            if (bricks < 0)
                return ans;
            ans++;
        }

        return ans;
    }
};
