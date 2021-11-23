/// <summary>
/// dfs approach
/// Time complexity : O(n), n being the number of nodes in tree
/// Space complexity : O(h), h being the tree height
/// https://leetcode.com/problems/binary-tree-right-side-view/
/// </summary>
class Solution {
public:
    void rec(TreeNode* root, vector<int>& res, int h) {
        if(not root)
            return;
        if(res.size() == h)
            res.push_back(root->val);
        rec(root->right, res, h + 1);
        rec(root->left, res, h + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rec(root, res, 0);
        return res;
    }
};