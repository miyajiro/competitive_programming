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

int K;
string S;
vi A;

vector<vvl> dp; // dp[n][k][isJust]: 上からn桁下ってて0以外の数字k個でisJustなら上からぴったり

void solve()
{
    cin >> S >> K;

    int N = sz(S);
    rep(i, N){
        A.eb(S[i] - '0');
    }

    dp = vector<vvl>(N, vvl(K + 1, vl(2, 0)));
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][0] = A[0] - 1;
    dp[0][1][1] = 1;

    rep(n, N - 1){
        int a = A[n + 1];

        rep(k, K + 1){
            // show(n);
            // show(k);
            // show(dp[n][k][0]);
            // show(dp[n][k][1]);

            // dp[n][k][0]から配るもの
            // - 0を選ぶ場合
            dp[n + 1][k][0] += dp[n][k][0];

            // - 数字を選ぶ場合
            if(k < K) {
                dp[n + 1][k + 1][0] += dp[n][k][0] * 9;
            }

            // dp[n][k][1]から配る
            if(a == 0){
                // 0を選ぶより他ない。
                dp[n + 1][k][1] = dp[n][k][1];
            } else {
                if(k < K){
                    // - 維持する場合
                    dp[n + 1][k + 1][1] += dp[n][k][1];

                    // - 維持せず、数字を選ぶ場合
                    dp[n + 1][k + 1][0] += dp[n][k][1] * (a - 1);
                }

                // - 維持せず、0を選ぶ場合
                dp[n + 1][k][0] += dp[n][k][1];
            }
        }
    }

    cout << dp[N - 1][K][0] + dp[N - 1][K][1] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}