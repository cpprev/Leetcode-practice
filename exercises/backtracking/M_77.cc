/// <summary>
/// backtracking approach
/// Time complexity : O(n!)
/// Space complexity : O(n!)
/// https://leetcode.com/problems/combinations/
/// </summary>
class Solution {
public:
    int N, K;

    void backtrack(vector<vector<int>>& comb, vector<int>& cur, int curN) {
        if (cur.size() == K) {
            comb.push_back(cur);
            return;
        }

        for (int i = curN; i <= N; ++i) {
            cur.push_back(i);
            backtrack(comb, cur, i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        vector<vector<int>> comb;
        vector<int> cur;
        backtrack(comb, cur, 1);
        return comb;
    }
};