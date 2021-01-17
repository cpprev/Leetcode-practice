/// <summary>
/// Hashmap approach
/// Time complexity : O(n^2)
/// Space complexity : O(n^2)
/// https://leetcode.com/problems/tuple-with-same-product/
/// </summary>
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> results;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int calc = nums[i] * nums[j];
                ++results[calc];
            }
        }

        int res = 0;
        for (auto& pair : results) {
            if (pair.second == 1 or pair.second == 0)
                continue;
            res += (pair.second - 1) * pair.second * 4;
        }
        return res;
    }
};