/// <summary>
/// DP where I store positions approach
/// https://leetcode.com/problems/longest-palindromic-substring/
/// </summary>
class Solution {
public:
    bool isPalindromic(const string& s, int begin, int end) {
        while (begin < end) {
            if (s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }

    string longestPalindrome(string s) {
        // map<letter, set<position>>  
        // stores positions for each letters

        // foreach letter : take all positions
        // and check if substring is palindromic
        // start from highest pos

        map<char, set<int>> pos;
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i]].insert(i);
        }

        int start = 0;
        int maxSize = 0;
        for (const auto& e : pos) {
            set<int> curPos = e.second;
            for (const auto& posA : curPos) {
                for (auto rit = curPos.rbegin(); rit != curPos.rend(); ++rit) {
                    int posB = *rit;
                    if (posA <= posB and posB - posA + 1 > maxSize) {
                        if (posB - posA + 1 > maxSize and isPalindromic(s, posA, posB)) {
                            start = posA;
                            maxSize = posB - posA + 1;
                            break;
                        }
                    }
                    else {
                        break;
                    }

                }
            }
        }
        return s.substr(start, maxSize);
    }
};