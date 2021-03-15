class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,int64_t> memo;
        unordered_map<int,int> numbers; // num, idx

        sort(arr.begin(), arr.end(), greater<int>());
        for (int i = 0; i < arr.size(); ++i)
            numbers[arr[i]] = i;

        function<int64_t(int)> dfs = [&](int idx) -> int64_t {
            int n = arr[idx];
            if (memo.count(n))
                return memo[n];

            memo[n] = 1; // self w/o children
            for (int i = idx; i < arr.size(); ++i) {
                if (n % arr[i] == 0 && numbers.count(n / arr[i]))
                    memo[n] += dfs(i) * dfs(numbers[n / arr[i]]) % 1000000007;
            }
            return memo[n];
        };

        for (int i = 0; i < arr.size(); ++i)
            dfs(i);
        int64_t result = 0;
        for (auto [kev,value] : memo) {
            result += value;
        }
        return result % 1000000007;
    }
};
