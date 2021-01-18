/// <summary>
/// dfs approach
/// Time complexity : O(n), n being the number of nodes in the tree
/// Space complexity : O(1)
/// https://leetcode.com/problems/validate-binary-search-tree/
/// </summary>
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* low, TreeNode* high)
    {
        if (not root)
            return true;

        if ((low and root->val <= low->val) or (high and root->val >= high->val))
            return false;

        return dfs(root->left, low, root) and dfs(root->right, root, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};