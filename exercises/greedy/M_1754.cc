/// <summary>
/// Greedy approach
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/largest-merge-of-two-strings/
/// </summary>
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int n1 = word1.size(), n2 = word2.size(), i = 0, j = 0;
        while (i < n1 or j < n2) {
            bool w1 = true;
            if (i < n1 and j < n2) {
                if (word1[i] < word2[j]) w1 = false;
                else if (word1.compare(i, n1, word2, j, n2) < 0) w1 = false;
            }
            else if (j < n2) w1 = false;
            
            if (w1) res += word1[i++];
            else res += word2[j++];
        }
        return res;
    }
};