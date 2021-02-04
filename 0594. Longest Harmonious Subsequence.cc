class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        int result = 0;

        for (auto i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (count.find(cur) == count.end())
                count[cur] = 1;
            else
                count[cur]++;

            if (count.find(cur - 1) != count.end())
                result = max(result, count[cur - 1] + count[cur]);
            if (count.find(cur + 1) != count.end())
                result = max(result, count[cur + 1] + count[cur]);
        }

        return result;
    }
};
