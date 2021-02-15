class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1,1};
        
        vector<int> prev = {1, 1};
        for (auto i = 2; i <= rowIndex; ++i) {
            vector<int> current;
            current.push_back(1);
            for (auto j = 1; j < i; ++j)
                current.push_back(prev[j-1] + prev[j]);
            current.push_back(1);
            prev.swap(current);
        }
        
        return prev;
    }
};
