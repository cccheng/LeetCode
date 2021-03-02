class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> visited(nums.size());
        vector<vector<int>> result;
        
        result.push_back({});
        
        function<void(int,vector<int>)> bt = [&](int len, vector<int> cur) {
            if (len > nums.size())
                return;
            
            cur.resize(len);
            for (int i = nums.size() - 1; i >= 0; --i) {
                if (visited[i])
                    return;
                visited[i] = true;
                cur[len - 1] = nums[i];
                result.push_back(cur);
                bt(len + 1, cur);
                visited[i] = false;
            }
        };
        
        bt(1, {});
        
        return result;
    }
};
