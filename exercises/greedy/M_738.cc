/// <summary>
/// Greedy approach
/// https://leetcode.com/problems/monotone-increasing-digits/
/// </summary>
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // go from right to left
        // decrease digits until a certain point
        // if this point == -1 return N,
        // else maximise the subint from the pos to the end
        
        string num = to_string(N);
        
        int pointer = -1;
        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i] < num[i - 1]) {
                num[i - 1] -= 1;
                pointer = i - 1;
            }
        }

        if (pointer == -1) {
            return N;
        }
        else {
            for (int i = pointer + 1; i < num.size(); ++i) {
                num[i] = '9';
            }
        }

        return stoi(num);
    }
};