/// <summary>
/// Two pointer approach
/// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
/// </summary>
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto cpy = nums;
        sort(cpy.begin(), cpy.end());

        int first = -1, last = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != cpy[i]) break;
            else first = i;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] != cpy[i]) break;
            else last = i;
        }

        if (last - first - 1 < 0) return 0;
        return last - first - 1;
    }
};