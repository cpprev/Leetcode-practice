/// <summary>
/// DP approach : every element in the dp matrix is equal to the sum of the possible previous step
/// ([i - 1][j] or [i][j - 1] since we can only go to the right or move down)
/// Time complexity : O(n*n)
/// Space complexity : O(m*n)
/// https://leetcode.com/problems/unique-paths/
/// </summary>
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 1; i < m; ++i) dp[i][0] = 1;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};