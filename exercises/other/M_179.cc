/// <summary>
/// Custom comparator approach
/// Time complexity : O(nlogn) with the sort
/// Space complexity : O(n)
/// https://leetcode.com/problems/largest-number/
/// </summary>
class Solution {
public:
    string largestNumber(vector<int>& numsIn) {
        vector<string> nums(nums.size());
        for (auto& n : numsIn) nums.emplace_back(to_string(n));

        sort(nums.begin(), nums.end(), [](const auto& num1, const auto& num2)
            {
                int i = 0, j = 0;
                while (i < num1.size() or j < num2.size()) {
                    if (i < num1.size() and j < num2.size()) {
                        if (num1[i] != num2[j]) return num1[i] > num2[j];
                        ++i;
                        ++j;
                    }
                    else if (i < num1.size()) j = 0;
                    else if (j < num2.size()) i = 0;
                }
                return false;
            });

        string res;
        for (auto& num : nums) res += (num);
        while (res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};