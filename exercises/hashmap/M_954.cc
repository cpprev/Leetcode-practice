/// <summary>
/// Store occurences in hashmap approach
/// Time complexity : O(nlogn) (because of sort)
/// Space complexity : O(n)
/// https://leetcode.com/problems/array-of-doubled-pairs/
/// </summary>
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> dp;
        for (auto& e : arr) ++dp[e];

        int n = arr.size(), res = 0;
        for (auto& elem : arr) {
            auto it = dp.find(elem);
            int occ = it->second;
            if (occ == 0 or (elem == 0 and occ % 2 == 1)) continue;
            
            auto dit = dp.find(2 * elem);
            if (dit != dp.end() and dit->second > 0) {
                --it->second;
                --dit->second;
                ++res;
            }
        }
        return res == n / 2;
    }
};