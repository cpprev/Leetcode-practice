/// <summary>
/// dfs approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
/// </summary>
class Solution {
public:
    bool dfs(TreeNode* root, int d, int& change, int& min) {
        if (not root) {
            if (d < min) {
                min = d;
                ++change;
            }
            return d <= min and change <= 2;
        }
        
        return dfs(root->left, d + 1, change, min) and dfs(root->right, d + 1, change, min);
    }
    
    bool isCompleteTree(TreeNode* root) {
        int min = INT_MAX, change = 0;
        return dfs(root, 0, change, min);
    }
};