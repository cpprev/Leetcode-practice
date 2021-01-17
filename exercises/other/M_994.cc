/// <summary>
/// Check if grid contains contaminable cells approach (beats 100% speed, beats 100% memory)
/// Time complexity : O(n*m), m and n being the matrix length and width
/// Space complexity : O(n*m)
/// https://leetcode.com/problems/rotting-oranges/
/// </summary>
class Solution {
public:
    bool isIsolated(vector<vector<int>>& grid, int i, int j) {
        if (j + 1 < grid[i].size() and grid[i][j + 1] != 0) return false;
        if (i + 1 < grid.size() and grid[i + 1][j] != 0) return false;
        if (j - 1 >= 0 and grid[i][j - 1] != 0) return false;
        if (i - 1 >= 0 and grid[i - 1][j] != 0) return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int count = -1;
        bool cont = true;
        while (cont) {
            cont = false;
            bool oneMark = false;
            vector<pair<int, int>> contamined;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[i].size(); ++j) {
                    if (grid[i][j] == 1) {
                        oneMark = true;
                        if (i - 1 >= 0 and grid[i - 1][j] == 2
                            or i + 1 < grid.size() and grid[i + 1][j] == 2
                            or j - 1 >= 0 and grid[i][j - 1] == 2
                            or j + 1 < grid[i].size() and grid[i][j + 1] == 2) {
                            cont = true;
                            contamined.push_back({ i, j });
                        }
                        else if (isIsolated(grid, i, j)) return -1;
                    }
                }
            }
            if (contamined.empty() and oneMark) return -1;

            for (auto& ij : contamined) grid[ij.first][ij.second] = 2;

            ++count;
        }

        return count;
    }
};