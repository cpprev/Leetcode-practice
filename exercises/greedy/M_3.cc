/// <summary>
/// Greedy approach (store positions of last occurence of each character)
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// </summary>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 128;
        int pos[size];
        for (int i = 0; i < size; ++i) pos[i] = -1;

        int max = 0, cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i] - ' ';
            int charIndex = pos[c];
            if (charIndex == -1 or (charIndex != -1 and charIndex < i - cur)) {
                ++cur;
                if (cur > max) max = cur;
            }
            else {
                cur = i - charIndex;
            }
            pos[c] = i;
        }
        return max;
    }
};