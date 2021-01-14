/// <summary>
/// Not the most optimal approach ( O(n) best case, but O(n^2) worst case )
/// https://leetcode.com/problems/longest-valid-parentheses/
/// </summary>
class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, countOp = 0, countCl = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (c == '(') ++countOp;
            else if (c == ')') ++countCl;

            if (countCl > countOp) {
                if (countCl - 1 + countOp > max)
                    max = countCl - 1 + countOp;
                countOp = 0;
                countCl = 0;
            }
            else if (countOp == countCl and countOp + countCl > max) {
                max = countOp + countCl;
            }
            else if (i == s.size() - 1 and countOp > countCl) {
                i = i - countOp - countCl + 1;
                countOp = 0;
                countCl = 0;
            }
        }
        return max;
    }
};