/// <summary>
/// backtracking approach
/// Time complexity : O(n!)
/// Space complexity : O(n!)
/// https://leetcode.com/problems/subsets/
/// </summary>
class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() <= nums.size()) res.push_back(cur);

        for (int i = index; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> c;
        backtrack(nums, 0, c, res);
        return res;
    }
};