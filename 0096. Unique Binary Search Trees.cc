class Solution {
public:
    int numTrees(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        result.push_back(2);
        result.push_back(5);
        
        for(int i = 4; i <= n; ++i) {
            int tmp = 0;
            for( int j = 0; j <= i - 1; ++j) {
                tmp += result[j] * result[i-j-1];
            }
            result.push_back(tmp);
        }
        
        return result[n];
    }
};
