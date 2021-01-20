/// <summary>
/// prefix sum approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/subarray-sum-equals-k/
/// </summary>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> pos;
        pos[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            sum = sum + nums[i];
            int key = sum - k;
            if (pos.count(key))
                res += pos[key];
            pos[sum] += 1;
        }
        return res;
    }
};