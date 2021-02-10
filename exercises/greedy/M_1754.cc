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
        while (not word1.empty() or not word2.empty()) {
            bool w1 = true;
            if (not word1.empty() and not word2.empty()) {
                if (word1[0] < word2[0]) w1 = false;
                else if (word1.compare(word2) < 0) w1 = false;
            }
            else if (not (word2.empty())) w1 = false;
            
            if (w1) {
                res += word1[0];
                word1.erase(word1.begin());
            }
            else {
                res += word2[0];
                word2.erase(word2.begin());
            }
        }
        return res;
    }
};