/// <summary>
/// backtracking approach
/// Time complexity : O(n!)
/// Space complexity : O(n!)
/// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/// </summary>
class Solution {
public:
    map<int, vector<char>> table =
    {
        { 2, { 'a', 'b', 'c' } },
        { 3, { 'd', 'e', 'f' } },
        { 4, { 'g', 'h', 'i' } },
        { 5, { 'j', 'k', 'l' } },
        { 6, { 'm', 'n', 'o' } },
        { 7, { 'p', 'q', 'r', 's' } },
        { 8, { 't', 'u', 'v' } },
        { 9, { 'w', 'x', 'y', 'z' } }
    };

    void dfs(string& digits, int index, string cur, vector<string>& res) {
        if (cur.size() == digits.size()) res.push_back(cur);
        if (index >= digits.size()) return;

        for (auto& p : table[digits[index] - '0']) {
            dfs(digits, index + 1, cur + p, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> res;
        dfs(digits, 0, "", res);
        return res;
    }
};