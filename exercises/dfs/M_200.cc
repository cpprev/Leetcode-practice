/// <summary>
/// simple dfs approach
/// https://leetcode.com/problems/number-of-islands/
/// </summary>
class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& seen, int i, int j) {
        if (i >= grid.size() or j >= grid[0].size() or i < 0 or j < 0
            or seen[i][j] or grid[i][j] == '0')
            return;
        seen[i][j] = true;

        dfs(grid, seen, i + 1, j);
        dfs(grid, seen, i, j + 1);
        dfs(grid, seen, i - 1, j);
        dfs(grid, seen, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (not seen[i][j] and grid[i][j] == '1') {
                    ++res;
                    dfs(grid, seen, i, j);
                }
            }
        }
        return res;
    }
};