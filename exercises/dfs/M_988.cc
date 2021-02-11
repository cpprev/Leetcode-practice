/// <summary>
/// dfs approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/smallest-string-starting-from-leaf/
/// </summary>
class Solution {
public:
    void dfs(TreeNode* root, string& cur, string& m) {
        if (not root) return;
        
        cur.insert(0, string(1, root->val + 'a'));
        
        if (not root->left and not root->right) {
            if (cur.compare(m) < 0) m = cur;
        }
        
        dfs(root->left, cur, m);
        dfs(root->right, cur, m);
        
        cur.erase(cur.begin());
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string m = "{", cur = "";
        dfs(root, cur, m);
        return m;
    }
};