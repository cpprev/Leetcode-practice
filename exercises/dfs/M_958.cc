/// <summary>
/// dfs approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
/// </summary>
class Solution {
public:
    bool dfs(TreeNode* root, int cur_d, int& change_count, int& min_d) {
        if (not root) {
            int dif = min_d - cur_d;
            if (dif > 0) {
                if (min_d != INT_MAX and dif != 1) return false;
                min_d = cur_d;
                ++change_count;
            }
            return dif >= 0 and change_count <= 2;
        }
        
        return dfs(root->left, cur_d + 1, change_count, min_d)
           and dfs(root->right, cur_d + 1, change_count, min_d);
    }
    
    bool isCompleteTree(TreeNode* root) {
        int min_depth = INT_MAX, change_count = 0;
        return dfs(root, 0, change_count, min_depth);
    }
};