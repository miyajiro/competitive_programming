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
#define show(x) cerr << #x << " = " << x << "\n";
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
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
int N, K;
vi A, B;
vp C;
vvvm dp;

void solve()
{
    cin >> N >> K;

    rep(i, N){
        int a;
        cin >> a;
        A.eb(--a);
    }

    rep(i, N){
        int b;
        cin >> b;
        B.eb(--b);
    }
    rep(i, N){
        C.eb(P(A[i], B[i]));
    }
    sort(rng(C));

    dp = vvvm(N + 1, vvm(K + 1, vm(N + 1, 0))); // dp[i][s][t]: i番目まで見て、s人選び、落とした人の一番いい成績がt位

    dp[0][0][N] = 1;

    rep(i, N){ // 配るDP
        rep(s, K + 1){
            rep(t, N + 1){
                // 受からせる場合
                if(s < K && t > C[i].sc){ // 募集人数余裕あり、落とした人よりいい順位
                    dp[i + 1][s + 1][t] += dp[i][s][t];
                }

                // 落とす場合
                dp[i + 1][s][min(t, C[i].sc)] += dp[i][s][t];
            }
        }
    }

    mint ans = 0;
    rep(i, N + 1){
        ans += dp[N][K][i];
    }

    cout << ans.val() << '\n';
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}