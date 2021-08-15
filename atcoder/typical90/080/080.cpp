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

int N, D;
vl A;
vvl dp;
vi d2S;

void solve()
{
    cin >> N >> D;

    if(D == 0){
        cout << "0\n";
        return;
    }

    dp = vvl(D + 1, vl(1 << N, 0)); // dp[d][s]; d桁目までで、集合sを満たす場合の数。配るDP
    d2S = vi(D, 0); // d2S[d]: dのビットを立てたときに被覆できる集合

    rep(n, N){
        ll a;
        cin >> a;
        A.eb(a);
    }

    rep(d, D){
        int s = 0;
        rep(n, N){
            ll a = A[n];
            if((a >> d) % 2LL == 1LL){
                s |= (1 << n);
            }
        }
        d2S[d] = s;
    }

    dp[0][0] += 1;
    dp[0][d2S[0]] += 1;

    rep(d, D - 1){
        rep(s, 1 << N){
            dp[d + 1][s] += dp[d][s]; // d+1ビット目立てない
            dp[d + 1][s | d2S[d + 1]] += dp[d][s]; // d+1ビット目立てる
        }
    }

    cout << dp[D - 1][(1 << N) - 1] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}