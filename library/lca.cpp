#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

/**
 * Lowest Common Ancestor
 */
struct LCA
{
private:
    int root;
    int k;                  // n<=2^kとなる最小のk
    vector<vector<int>> dp; // dp[i][j]:=要素jの2^i上の要素
    vector<int> depth;      // depth[i]:=rootに対する頂点iの深さ

public:
    LCA(const vector<vector<int>> &_G, const int _root = 0)
    {
        int n = _G.size();
        root = _root;
        k = 1;
        int nibeki = 2;
        while (nibeki < n)
        {
            nibeki <<= 1;
            k++;
        }
        // 頂点iの親ノードを初期化
        dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
        depth.resize(n);
        function<void(int, int)> _dfs = [&](int v, int p) {
            dp[0][v] = p;
            for (auto nv : _G[v])
            {
                if (nv == p)
                    continue;
                depth[nv] = depth[v] + 1;
                _dfs(nv, v);
            }
        };
        _dfs(root, -1);
        // ダブリング
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == -1)
                    continue;
                dp[i + 1][j] = dp[i][dp[i][j]];
            }
        }
    }

    /// get LCA
    int get(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v); // u側を深くする
        if (depth[u] != depth[v])
        {
            long long d = depth[u] - depth[v];
            for (int i = 0; i < k; i++)
                if ((d >> i) & 1)
                    u = dp[i][u];
        }
        if (u == v)
            return u;

        for (int i = k; i >= 0; i--)
        {
            if (dp[i][u] != dp[i][v])
            {
                u = dp[i][u], v = dp[i][v];
            }
        }
        return dp[0][u];
    }

    int get_distance(const int u, const int v)
    {
        int lca = get(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
};