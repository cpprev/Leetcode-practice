/// <summary>
/// Greedy approach
/// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
/// </summary>
class Solution {
public:
    int minDeletions(string s) {
        int occPerChar[26];
        memset(occPerChar, 0, sizeof(occPerChar));
        for (auto& ch : s) ++occPerChar[ch - 'a'];

        multiset<int> occs;
        for (int i = 0; i < 26; ++i) occs.insert(occPerChar[i]);

        int nbDel = 0;
        for (auto it = occs.begin(); it != occs.end(); ++it) {
            int elm = *it;
            if (occs.count(elm) > 1) {
                while (elm > 0) {
                    --elm;
                    ++nbDel;
                    if (occs.count(elm) == 0) {
                        occs.insert(elm);
                        break;
                    }
                }
                occs.erase(it);
            }
        }
        return nbDel;
    }
};