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

int N;
vector<P> AB;
vi A, B;
vector<vector<mint>> dp;

void solve()
{
    cin >> N;
    dp = vector<vector<mint>>(N + 1, vector<mint>(5001, 0));

    rep(i, N){
        int a;
        cin >> a;
        A.eb(a);
    }
    rep(i, N){
        int b;
        cin >> b;
        B.eb(b);
        AB.eb(P(A[i], b));
    }
    sort(rng(AB));
    rep(i, N){
        A[i] = AB[i].fr;
        B[i] = AB[i].sc;
    }

    mint ans = 0;
    dp[0][0] = 1; // dp[i][x] 0~i-1でx作る場合の数

    rep(ni, N){
        int a = A[ni];
        int b = B[ni];
        int prevVal = a - b;
        if(prevVal >= 0){ // 作るチャンス
            rep(x, prevVal + 1){
                ans += dp[ni][x];
            }
        }

        rrep(x, 5001){ // ni+1, xを作っていく
            dp[ni + 1][x] = dp[ni][x]; // bを使わない場合
            if(x - b >= 0){
                dp[ni + 1][x] += dp[ni][x - b]; // bを使う場合
            }
        }
    }

    cout << ans.val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}