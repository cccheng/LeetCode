class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int>> min_heap;

        for (auto n : nums1)
            max_heap.push(n);
        for (auto n : nums2)
            max_heap.push(n);

        while (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        if (max_heap.size() > min_heap.size())
            return max_heap.top();
        else if (max_heap.size() < min_heap.size())
            return min_heap.top();
        else
            return ((double)max_heap.top() + min_heap.top()) / 2;
    }
};
