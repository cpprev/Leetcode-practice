/// <summary>
/// Two pointers approach (O(n) time, O(n) space)
/// https://leetcode.com/problems/container-with-most-water/
/// </summary>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, mx = -1;
        while (left < right) {
            int cur = (right - left) * std::min(height[left], height[right]);
            mx = std::max(mx, cur);
            if (height[left] < height[right])
                left = left + 1;
            else
                right = right - 1;
        }
        return mx;
    }
};