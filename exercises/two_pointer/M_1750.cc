/// <summary>
/// Two pointers approach
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
/// </summary>
class Solution {
public:
    int minimumLength(string s) {
        int begin = 0, end = s.size() - 1;
        char r = '\0';
        while (end >= begin) {
            if (begin != end and s[begin] == s[end]) {
                r = s[begin];
                ++begin;
                --end;
            }
            else if (s[begin] == r) ++begin;
            else if (s[end] == r) --end;
            else break;
        }
        return end - begin + 1;
    }
};