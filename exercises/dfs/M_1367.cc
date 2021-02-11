/// <summary>
/// dfs approach
/// Time complexity : O(n^2)
/// Space complexity : O(n^2)
/// https://leetcode.com/problems/linked-list-in-binary-tree/
/// </summary>
class Solution {
public:
    bool dfs(ListNode* cur, TreeNode* root) {
        if (not cur) return true;
        if (not root or root->val != cur->val) return false;
            
        return dfs(cur->next, root->left) or dfs(cur->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (not root) return false;
        return dfs(head, root) or isSubPath(head, root->left) or isSubPath(head, root->right);
    }
};