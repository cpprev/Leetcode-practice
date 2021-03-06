/// <summary>
/// dp approach
/// Time complexity : O(n^2)
/// Space complexity : O(n^2)
/// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
/// </summary>
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long dp[d + 1][target + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int k = 1; k <= f; ++k) {
                    if (j - k >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % (int(1e9) + 7);
                    }
                }
            }
        }
        return dp[d][target];
    }
};
