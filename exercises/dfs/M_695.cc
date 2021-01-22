/// <summary>
/// dfs approach
/// Time complexity : O(m * n)
/// Space complexity : O(m * n)
/// https://leetcode.com/problems/max-area-of-island/
/// </summary>
class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& seen, int i, int j) {
        if (i < 0 or i >= m or j < 0 or j >= n or seen[i][j] or grid[i][j] == 0) return 0;

        seen[i][j] = true;

        return 1 + dfs(grid, seen, i + 1, j) + dfs(grid, seen, i - 1, j)
                 + dfs(grid, seen, i, j + 1) + dfs(grid, seen, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (not seen[i][j] and grid[i][j] == 1) {
                    int local = dfs(grid, seen, i, j);
                    max = std::max(max, local);
                }
            }
        }
        return max;
    }
};