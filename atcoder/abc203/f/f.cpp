#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

const ll INF = 0xffffffffff;
ll N, K;
vl A;
vector<vl> dp; // dp[i][t] i番目までの草で、Tの操作回数tでのAの操作回数の最小値

// dp[i][t] = dp[i-1][t] + 1, dp[halfi][t - 1]

void solve()
{
    cin >> N >> K;
    dp = vector<vl>(N, vl(32, INF));
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
    }
    sort(rng(A));

    rep(ni, N){
        rep(t, 32){
            if(t == 0){
                dp[ni][t] = ni + 1LL;
                continue;
            }
            if(ni > 0){
                chmin(dp[ni][t], dp[ni-1][t] + 1LL);
            }
            int halfNi = upper_bound(rng(A), A[ni] / 2LL) - A.begin() - 1;

            if(halfNi == -1){ // 0~niまで全部tで抜けるので
                dp[ni][t] = 0;
                continue;
            }
            chmin(dp[ni][t], dp[halfNi][t-1]);
        }
    }

    ll ansT = INF, ansA = INF;
    rep(t, 32){
        if(dp[N - 1][t] <= K){
            ansT = t;
            ansA = dp[N - 1][t];
            break;
        }
    }
    cout << ansT << " " << ansA << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}