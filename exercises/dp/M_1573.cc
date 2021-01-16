/// <summary>
/// DP approach
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/number-of-ways-to-split-a-string/
/// </summary>
class Solution {
public:
    int numWays(string s) {
        int MOD = int(1e9) + 7;
        long n = s.size();

        int nbOnes = 0;
        for (auto& c : s)
            if (c == '1') ++nbOnes;

        if (nbOnes == 0) {
            long r = ((n - 2) * (n - 1)) / 2;
            return r % MOD;
        }
        if (nbOnes % 3 != 0) return 0;

        int maxOnes = nbOnes / 3;

        int dp[1];
        dp[0] = 1;

        int i = 1;
        while (i <= n and s[i - 1] != '1') ++i;

        int countLocalOnes = 0;
        int hitNumberOfAllowedOnes = 0;
        int retenue = 1;
        for (; i <= n; ++i) {
            if (s[i - 1] == '1')
                countLocalOnes++;

            if (countLocalOnes == maxOnes) {
                hitNumberOfAllowedOnes++;
                countLocalOnes = 0;
                if (hitNumberOfAllowedOnes == 3) break;
                retenue = dp[0];
            }
            else {
                if (countLocalOnes == 0 and s[i - 1] == '0') {
                    dp[0] = (dp[0] + retenue) % MOD;
                }
            }
        }

        return dp[0];
    }
};