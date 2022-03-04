#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/modint>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder{};
using namespace atcoder;
using namespace std;

#define fr first
#define sc second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i >= 1; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define snuke srand((unsigned)clock() + (unsigned)time(NULL));
#define show(x) 1;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline cout << "\n"
#define newlineErr cerr << "\n"

using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vp = vector<P>;
using vlp = vector<LP>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using mint = modint998244353;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

inline int getInt()
{
    int x;
    scanf("%d", &x);
    return x;
}
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

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

    int getPar(const int u){
        return dp[0][u];
    }
};

// 0が頂点

int N, M, K, S, T;
vi A, U, V;
vi B;
vvi G;
map<P, int> mp;

void solve()
{
    cin >> N >> M >> K;
    G = vvi(N);
    B = vi(N);
    rep(i, M){
        int a;
        cin >> a;
        A.eb(--a);
    }
    rep(i, N - 1){
        int u, v;
        cin >> u >> v;
        U.eb(--u);
        V.eb(--v);
        G[u].eb(v);
        G[v].eb(u);
        mp[P(u, v)] = i;
        mp[P(v, u)] = i;
    }

    LCA lca(G);
    rep(i, M - 1){
        int a = A[i];
        int b = A[i + 1];

        int c = lca.get(a, b);
        show(a);
        show(b);
        show(c);
        while(a != c){
            int par = lca.getPar(a);

            int edgeNum = mp[P(a, par)];
            B[edgeNum]++;
            S++;

            a = par;
        }

        while(b != c){
            int par = lca.getPar(b);

            int edgeNum = mp[P(b, par)];
            B[edgeNum]++;
            S++;

            b = par;
        }
    }

    // R + B = S
    // R - B = K
    // B = (S - K) / 2
    if(S - K < 0 || S + K < 0 || (S - K) % 2 == 1){
        cout << "0\n";
        return;
    }

    N--;
    T = min((S - K) / 2, (S + K) / 2);

    // N個の数字から選んだやつの合計をTにする場合の数
    vvm dp(2, vm(T + 1));
    dp[1][0] = 1;

    rep(i, N){
        show(i);
        show(B[i]);
    }

    int now, past;
    rep(i, N){ // 貰うDP
        now = i % 2;
        past = 1 - now;
        int b = B[i];

        rep(t, T + 1){
            dp[now][t] = dp[past][t];
            if(t - b >= 0){
                dp[now][t] += dp[past][t - b];
            }
        }
    }

    cout << dp[now][T].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}