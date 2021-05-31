#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
#include <atcoder/dsu>
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
#define show(x) cerr << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vp = vector<P>;
using vlp = vector<LP>;
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

const ll INF = 0xfffffffffffff;


/**
 * Lowest Common Ancestor
 */
struct LCA
{
private:
    ll root;
    ll k;                  // n<=2^kとなる最小のk
    vector<vector<LP>> dp; // dp[i][j]:=LP(要素jの2^i上の要素, jからその要素までのDの最小値)
    vector<ll> depth;      // depth[i]:=rootに対する頂点iの深さ
    vector<ll> D;

public:
    LCA(const vector<vector<ll>> &_G, const vector<ll> &_D, const ll _root = 0)
    {
        D = _D;
        ll n = _G.size();
        root = _root;
        k = 1;
        ll nibeki = 2;
        while (nibeki < n)
        {
            nibeki <<= 1;
            k++;
        }
        // 頂点iの親ノードを初期化
        dp = vector<vector<LP>>(k + 1, vector<LP>(n, LP(-1LL, INF)));
        depth.resize(n);
        function<void(ll, ll)> _dfs = [&](ll v, ll p) {
            ll D_p = INF, D_v = INF;
            if(p != -1LL){
                D_p = D[p];
            }
            D_v = D[v];

            dp[0][v] = LP(p, min(D_p, D_v));
            for (auto nv : _G[v])
            {
                if (nv == p)
                    continue;
                depth[nv] = depth[v] + 1;
                _dfs(nv, v);
            }
        };
        _dfs(root, -1LL);
        // ダブリング
        for (ll i = 0; i < k; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                LP dp1 = dp[i][j];
                if (dp1.fr == -1LL){
                    dp[i + 1][j] = dp1;
                    continue;
                }

                LP dp2 = dp[i][dp1.fr];
                ll D_1 = dp1.sc;
                ll D_2 = dp2.sc;
                dp[i + 1][j] = LP(dp2.fr, min(D_1, D_2));
            }
        }
    }

    /// get LCA
    LP get(ll u, ll v)
    {
        if (depth[u] < depth[v])
            swap(u, v); // u側を深くする

        ll D_u = D[u];
        ll D_v = D[v];

        if (depth[u] != depth[v])
        {
            long long d = depth[u] - depth[v];
            for (ll i = 0; i < k; i++) {
                if ((d >> i) & 1){
                    chmin(D_u, dp[i][u].sc);
                    u = dp[i][u].fr;
                }
            }
        }
        if (u == v)
            return LP(u, min(D_u, D_v));

        for (ll i = k; i >= 0; i--)
        {
            if (dp[i][u].fr != dp[i][v].fr)
            {
                chmin(D_u, dp[i][u].sc);
                u = dp[i][u].fr;

                chmin(D_v, dp[i][v].sc);
                v = dp[i][v].fr;
            }
        }
        return LP(dp[0][u].fr, min({D_u, D_v, dp[0][u].sc}));
    }
};


ll N, oldM, M, K, Q;
vl oldA, oldB, A, B, L, F;
vl D;
vector<vector<LP>> toAndCostArray;
PQ(LP) pq;

void solve()
{
    cin >> N >> oldM >> K >> Q;
    toAndCostArray = vector<vlp>(N);
    rep(m, oldM){
        ll a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        oldA.pb(a);
        oldB.pb(b);
        toAndCostArray[a].pb(LP(b, l));
        toAndCostArray[b].pb(LP(a, l));
        L.pb(l);
    }

    D = vl(N, INF);
    rep(k, K){
        ll f;
        cin >> f;
        f--;
        F.pb(f);
        D[f] = 0;
        pq.push(LP(0, f));
    }

    while(!pq.empty()){
        LP lp = pq.top();
        pq.pop();
        ll now = lp.sc;
        if(D[now] < lp.fr){
            continue;
        }

        for(auto toAndCost : toAndCostArray[now]){
            ll to = toAndCost.fr;
            ll cost = toAndCost.sc;
            if(chmin(D[to], D[now] + cost)){
                pq.push(LP(D[to], to));
            }
        }
    }

    M = 0;
    dsu DSU(N);

    vector<LP> minDAndMIndexArray;
    rep(m, oldM){
        ll da = D[oldA[m]];
        ll db = D[oldB[m]];
        minDAndMIndexArray.pb(LP(min(da, db), m));
    }

    sort(rrng(minDAndMIndexArray));

    for(auto minDAndMIndex : minDAndMIndexArray){
        ll oldMi = minDAndMIndex.sc;
        ll a = oldA[oldMi];
        ll b = oldB[oldMi];
        if(DSU.same(a, b)){
            continue;
        }

        DSU.merge(a, b);
        M++;
        A.pb(a);
        B.pb(b);
        if(M == N - 1LL){
            break;
        }
    }

    // N, M, A, B, D
    vector<vl> G = vector<vl>(N);
    rep(m, M){
        ll a = A[m];
        ll b = B[m];
        G[a].pb(b);
        G[b].pb(a);
    }

    LCA lca(G, D);

    rep(q, Q){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << (lca.get(a, b).sc) << "\n";
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}