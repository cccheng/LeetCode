
int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){

    // max_money(n) = max(
    //      nums(n) + max_money(n - 2),
    //      max_money(n - 1)
    // )

    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        return max(nums[0], nums[1]);
    }

    int prev1 = max(nums[0], nums[1]);
    int prev2 = nums[0];
    int cur_max = prev1;

    for (size_t i = 2; i < numsSize; ++i) {
        cur_max = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = cur_max;
    }

    return cur_max;
}


