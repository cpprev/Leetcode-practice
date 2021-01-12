/// <summary>
/// DFS approach
/// https://leetcode.com/problems/number-of-provinces/
/// </summary>
class Solution {
public:
    void dfs(map<int, vector<int>>& adj, int cur, vector<int>& mapped, int curInc) {
        if (mapped[cur] != -1) {
            return;
        }
        mapped[cur] = curInc;

        for (auto& vertex : adj[cur]) {
            dfs(adj, vertex, mapped, curInc);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> mapped(n, -1);
        map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int curInc = 0;
        for (auto& a : adj) {
            int vertex = a.first;

            if (mapped[vertex] == -1) {
                dfs(adj, vertex, mapped, curInc);
                curInc++;
            }

        }

        return curInc;
    }
};