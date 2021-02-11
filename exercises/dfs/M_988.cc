/// <summary>
/// dfs approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/smallest-string-starting-from-leaf/
/// </summary>
class Solution {
public:
    void dfs(TreeNode* root, string cur, string& m) {
        if (not root) return;
        
        cur += root->val + 'a';
        
        if (not root->left and not root->right) {
            reverse(cur.begin(), cur.end());
            if (cur.compare(m) < 0) {
                m = cur;
            }
            return;
        }
        
        dfs(root->left, cur, m);
        dfs(root->right, cur, m);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string m = "{";
        dfs(root, "", m);
        return m;
    }
};