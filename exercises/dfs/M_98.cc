/// <summary>
/// dfs approach
/// Time complexity : O(n), n being the number of nodes in the tree
/// Space complexity : O(n)
/// https://leetcode.com/problems/validate-binary-search-tree/
/// </summary>
class Solution {
public:
    bool dfs(TreeNode* root, int low, int high)
    {
        if (not root)
            return true;

        if ((low != -1 and root->val <= low) or (high != -1 and root->val >= high))
            return false;

        return dfs(root->left, low, root->val) and dfs(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, -1, -1);
    }
};