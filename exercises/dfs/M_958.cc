/// <summary>
/// dfs approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
/// </summary>
class Solution {
public:
    bool dfs(TreeNode* root, int cur_d, int& change, int& min_d) {
        if (not root) {
            if (cur_d < min_d) {
                min_d = cur_d;
                ++change;
            }
            return cur_d <= min_d and change <= 2;
        }
        
        return dfs(root->left, cur_d + 1, change, min_d)
           and dfs(root->right, cur_d + 1, change, min_d);
    }
    
    bool isCompleteTree(TreeNode* root) {
        int min_depth = INT_MAX, change = 0;
        return dfs(root, 0, change, min_depth);
    }
};