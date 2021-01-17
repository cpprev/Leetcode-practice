/// <summary>
/// DP approach
/// Time complexity : O(n^m)
/// Space complexity : O(n^m)
/// https://leetcode.com/problems/largest-submatrix-with-rearrangements/
/// </summary>
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), max = 0;

        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i - 1 < 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            map<int, int> occ;
            set<int> diff;
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                occ[dp[i][j]]++;
                diff.insert(dp[i][j]);
            }

            for (auto& p : occ) {
                int num = p.first, nbOcc = p.second;
                auto it = ++diff.find(num);
                for (; it != diff.end(); ++it) nbOcc += occ[*it];

                if (num * nbOcc > max) max = num * nbOcc;
            }
        }

        return max;
    }
};