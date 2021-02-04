class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> max_heap(nums.begin(), nums.end());

        int result;
        while (k--) {
            result = max_heap.top();
            max_heap.pop();

        }
        return result;
    }
};
