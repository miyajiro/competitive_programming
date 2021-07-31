#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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
#define show(x) cout << #x << " = " << x << endl;
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
using vvl = vector<vl>;
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

using mint = modint998244353;
int N, M, K;
vi U, V;
mint dp[5001][5000]; // dp[i][j] i日目に都市jにいる場合の数
vi notFrom[5000]; // ここからはこれないよ

void solve()
{
    cin >> N >> M >> K;

    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        U.eb(u);
        V.eb(v);

        notFrom[u].eb(v);
        notFrom[v].eb(u);
    }

    rep(i, N){
        notFrom[i].eb(i);
    }

    rep(i, K + 1){
        rep(j, N){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    mint pastSum = 1;
    mint nowSum = 0;
    mint nfSum = 0;

    rep1(k, K){ // k日目
        nowSum = 0;

        rep(n, N){ // 都市nにいる場合の数
            nfSum = 0;
            for(auto nf : notFrom[n]){
                nfSum += dp[k - 1][nf];
            }
            dp[k][n] = pastSum - nfSum;
            nowSum += dp[k][n];
        }

        swap(pastSum, nowSum);
    }

    cout << dp[K][0].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}