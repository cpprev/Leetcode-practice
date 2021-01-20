/// <summary>
/// prefix sum approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/subarray-sum-equals-k/
/// </summary>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, res = 0;
        // In this map we store the prefix sums [nums[0], nums[0] + nums[1], ...]
        unordered_map<int, int> F;
        F[0] = 1;
        for (int i = 0; i < n; ++i) {
            // Important : F[i] - F[j] = sums(i::j)
            // Here, we look for all : F[i] - F[j] = k, to find what we want
            // So, F[j] = F[i] - k (ie: key = sum - k)
            sum += nums[i];
            int key = sum - k;
            if (F.count(key))
                res += F[key];
            F[sum] += 1;
        }
        return res;
    }
};