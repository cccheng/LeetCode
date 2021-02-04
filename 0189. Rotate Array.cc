class Solution {
public:
    void reverse(vector<int>& arr, int offset, int length) {
        int i = offset, j = offset + length - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size() - k);
    }
};
