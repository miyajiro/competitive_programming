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

int N, L;
vi X;
int Q;
vi A, B;
vvi dp;

void solve()
{
    cin >> N;
    dp = vvi(N, vi(18, 0)); // dp[n][b]: ホテルnから2^b日で到達できる最後のホテル
    rep(_, N){
        int x;
        cin >> x;
        X.pb(x);
    }
    cin >> L >> Q;
    rep(_, Q){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        A.pb(--a);
        B.pb(--b);
    }

    rep(ni, N){
        int x = X[ni];
        int farthestReachableHotel = upper_bound(rng(X), x + L) - X.begin() - 1;
        dp[ni][0] = farthestReachableHotel;
    }


    rep1(i, 17){
        rep(x, N){
            dp[x][i] = dp[dp[x][i-1]][i-1];
        }
    }

    rep(q, Q){
        int a = A[q];
        int b = B[q];
        int ans = 0;
        rrep(i, 18){
            if(dp[a][i] < b){
                a = dp[a][i];
                ans += (1 << i);
            }
        }
        cout << ans + 1 << "\n";
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