/// <summary>
/// dp approach
/// Time complexity : O(n*m)
/// Space complexity : O(n*m)
/// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
/// </summary>
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> vals;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    matrix[i][j] ^= matrix[i - 1][j];
                if (j > 0)
                    matrix[i][j] ^= matrix[i][j - 1];
                if (i > 0 and j > 0)
                    matrix[i][j] ^= matrix[i - 1][j - 1];

                vals.push_back(matrix[i][j]);
            }
        }

        sort(vals.begin(), vals.end());
        return vals[vals.size() - k];
    }
};
