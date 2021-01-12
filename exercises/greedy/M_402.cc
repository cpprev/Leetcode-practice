/// <summary>
/// Greedy approach
/// https://leetcode.com/problems/remove-k-digits/
/// </summary>
class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < num.size() and k > 0; ++i) {
            if (num[i] > num[i + 1]) {
                num.erase(num.begin() + i);
                --k;
                if (i < num.size()) {
                    while (k > 0 and i - 1 >= 0 and num[i - 1] > num[i]) {
                        num.erase(num.begin() + i - 1);
                        --k;
                        --i;
                    }
                }
                --i;
            }
        }
        if (k > 0) {
            num.erase(num.size() - k, k);
        }

        while (num[0] == '0') {
            num.erase(num.begin());
        }
        if (num.empty())
            return "0";
        return num;
    }
};