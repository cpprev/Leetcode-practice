/// <summary>
/// DP approach
/// Time complexity : O(n^2)
/// Space complexity : O(n^2)
/// https://leetcode.com/problems/triangle/
/// </summary>
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>());
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[i].push_back(0);
            }
        }
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                // 1 parent
                int parent = -1;
                if (j != 0) {
                    // 2 parents
                    if (j < triangle[i - 1].size()) {
                        parent = min(dp[i - 1][j], dp[i - 1][j - 1]);
                    }
                    else {
                        parent = dp[i - 1][j - 1];
                    }

                }
                else {
                    parent = dp[i - 1][j];
                }
                dp[i][j] = triangle[i][j] + parent;
            }
        }

        vector<int> vec = dp[triangle.size() - 1];
        return *min_element(vec.begin(), vec.end());
    }
};
