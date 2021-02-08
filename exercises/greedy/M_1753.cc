/// <summary>
/// Greedy approach (decrement the 2 largest current numbers)
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/maximum-score-from-removing-stones/
/// </summary>
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int res = 0;
        vector<int> arr = { a, b, c };
        sort(arr.begin(), arr.end());
        while (arr[1] != 0) {            
            --arr[2];
            --arr[1];
            ++res;
            sort(arr.begin(), arr.end());
        }
        return res;
    }
};