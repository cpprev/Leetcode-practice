/// <summary>
/// dfs approach
/// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
/// </summary>
class Solution {
public:

    void rec(vector<bool>& seen, map<int, set<int>>& pointer, map<int, set<int>>& pointed,
        int current, int& res) {
        seen[current] = true;

        // check every node that the current is pointing to
        for (auto& dst : pointer[current]) {
            if (seen[dst]) {
                continue;
            }
            ++res;
            rec(seen, pointer, pointed, dst, res);
        }

        // check every node that points to the current
        for (auto& src : pointed[current]) {
            if (seen[src]) {
                continue;
            }
            rec(seen, pointer, pointed, src, res);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // map<src, set<dst>>
        map<int, set<int>> pointer;
        // map<dst, set<src>>
        map<int, set<int>> pointed;

        vector<bool> seen(connections.size() + 1, false);

        for (auto& conn : connections) {
            int src = conn[0], dst = conn[1];
            pointer[src].insert(dst);
            pointed[dst].insert(src);
        }

        int res = 0;
        rec(seen, pointer, pointed, 0, res);
        return res;
    }
};