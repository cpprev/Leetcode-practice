/// <summary>
/// dfs approach
/// https://leetcode.com/problems/generate-parentheses/
/// </summary>
class Solution {
public:
    void rec(string cur, int open, int closed, vector<string>& res) {
        if (open == 0 and closed == 0) {
            res.push_back(cur);
        }
        if (open > 0) {
            rec(cur + '(', open - 1, closed + 1, res);
        }
        if (closed > 0) {
            rec(cur + ')', open, closed - 1, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec("", n, 0, res);
        return res;
    }
};