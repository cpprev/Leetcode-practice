/// <summary>
/// dfs approach (2 passes in the tree)
/// Time complexity : O(n), n being the number of nodes in the tree
/// Space complexity : O(n)
/// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
/// </summary>
class Solution {
public:
    int sum, MOD = int(1e9) + 7;
    pair<long, long> max = { 0, 0 };

    int getsum(TreeNode* root) {
        if (not root) return 0;
        return root->val + getsum(root->left) + getsum(root->right);
    }

    int dfs(TreeNode* root) {
        if (not root) return 0;

        long left = dfs(root->left);
        long right = dfs(root->right);

        long local = left * (sum - left);
        if (local > max.first * max.second) max = { left, sum - left };

        local = right * (sum - right);
        if (local > max.first * max.second) max = { right, sum - right };

        return root->val + left + right;
    }

    int maxProduct(TreeNode* root) {
        sum = getsum(root);

        dfs(root);

        return (max.first * max.second) % MOD;
    }
};