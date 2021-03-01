class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count;
        for (auto n : nums)
            count[n]++;
        
        vector<pair<int,int>> freq;
        for (auto kv : count)
            freq.push_back(kv);
        
        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });
        
        vector<int> result;
        for (int i = 0; i < k; ++i)
            result.push_back(freq[i].first);
        
        return result;
    }
};
