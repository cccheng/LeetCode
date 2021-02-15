class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result(k);
        
        auto cmp = [](const pair<int,int> left, const pair<int,int> right) -> bool {
            if (left.second != right.second)
                return left.second < right.second;
            return left.first < right.first;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> max_heap(cmp);
        
        for (auto i = 0; i < mat.size(); ++i) {
            int score = 0;
            
            for (auto j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0)
                    score++;
                else {
                    score += (100 - j);
                }
            }
            
            max_heap.push({i, score});
            if (max_heap.size() > k)
                max_heap.pop();
        }
        
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = max_heap.top().first;
            max_heap.pop();
        }
        
        return result;
    }
};
