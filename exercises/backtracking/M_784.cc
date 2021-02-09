/// <summary>
/// Backtracking approach
/// Time complexity : O(n!)
/// Space complexity : O(n!)
/// https://leetcode.com/problems/letter-case-permutation/
/// </summary>
class Solution {
public:
    void backtrack(string& cur, int ind, vector<string>& res) {
        res.push_back(cur);
        
        for (int i = ind; i < cur.size(); ++i) {
            char c = cur[i];
            if (c >= 'a' and c <= 'z') {
                cur[i] = toupper(c);
                backtrack(cur, i + 1, res);
            }
            else if (c >= 'A' and c <= 'Z') {
                cur[i] = tolower(c);
                backtrack(cur, i + 1, res);
            }
            else
                continue;
            cur[i] = c;
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};