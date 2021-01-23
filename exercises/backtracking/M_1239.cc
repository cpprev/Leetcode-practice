/// <summary>
/// backtracking approach
/// Time complexity : O(n^2)
/// Space complexity : O(1)
/// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
/// </summary>
class Solution {
public:
    bool valid(const string& s) {
        int occ[26] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            if (occ[s[i] - 'a'] == 1) return false;
            else occ[s[i] - 'a']++;
        }
        return true;
    }

    void backtrack(vector<string>& arr, int index, string cur, size_t& longest) {
        if (not valid(cur)) return;

        longest = std::max(longest, cur.size());

        for (int i = index; i < arr.size(); ++i)
            backtrack(arr, i + 1, cur + arr[i], longest);
    }

    int maxLength(vector<string>& arr) {
        size_t longest = 0;
        backtrack(arr, 0, "", longest);
        return longest;
    }
};