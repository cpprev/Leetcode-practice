/// <summary>
/// prefix sum approach
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/subarray-sums-divisible-by-k/
/// </summary>
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size(), sum = 0, res = 0;
        unordered_map<int, int> F{ {0, 1} };
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            int key = sum % K < 0 ? sum % K + K : sum % K;
            if (F.count(key))
                res += F[key];
            ++F[key];
        }
        return res;
    }
};