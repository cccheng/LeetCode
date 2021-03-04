class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int num = arr.size();
        vector<int> result;

        for (int i = num; i >= 1; --i) {
            auto iter = find(arr.begin(), arr.end(), i);
            if (iter == arr.begin() + i - 1)
                continue;

            if (iter != arr.begin()) {
                result.push_back(distance(arr.begin(), iter) + 1);
                reverse(arr.begin(), iter + 1);
            }
            // rotate to i from back
            result.push_back(i);
            reverse(arr.begin(), arr.begin() + i);
        }

        return result;
    }
};
