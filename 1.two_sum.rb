# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    nums.each_with_index do |val, i|
        (i+1 ... nums.size).each do |j|
            return [i, j] if target == nums[i] + nums[j]
        end
    end
end
