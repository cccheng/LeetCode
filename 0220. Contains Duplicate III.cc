class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> win;

        for (int i = 0; i < nums.size(); ++i) {
            long n = nums[i];
            if (win.size() > k)
                win.erase(nums[i-k-1]);

            auto it = win.lower_bound(n - t);
            if (it != win.end() && *it - n <= t)
                return true;

            win.insert(n);
        }

        return false;
    }
};
