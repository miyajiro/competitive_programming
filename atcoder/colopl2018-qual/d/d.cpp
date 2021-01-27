#include <bits/stdc++.h>
#include <atcoder/all>
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
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
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

ll N, X;
vl T;

vv(ll) dp;
v(ll) ans;

int main()
{
    cin >> N >> X;
    rep(i, N)
    {
        ll t;
        cin >> t;
        T.pb(t);
        dp.pb(vl(N + 1, 0));
        ans.pb(0LL);
    }
    ans.pb(0LL);
    // dp[n][k]: 最後に起動したのがnで、それまでにk回消費の最大値
    dp[0][1] = X;

    rep(n, N)
    {
        rep(k, N)
        {
            // dp[n][k]からの遷移はT[n]+X以上の最初の要素とその下だけ見れば良い。
            ll lowerN = (lower_bound(rng(T), T[n] + X) - T.begin());
            if (lowerN < T.size())
            {
                dp[lowerN][k + 1] = max(dp[lowerN][k + 1], dp[n][k] + min(X, T[lowerN] - T[n]));
            }
            if (lowerN - 1 > n)
            {
                dp[lowerN - 1][k + 1] = max(dp[lowerN - 1][k + 1], dp[n][k] + min(X, T[lowerN - 1] - T[n]));
            }
        }
    }

    rep(n, N)
    {
        rep(k, N + 1)
        {
            // cout << "dp[" << n << "][" << k << "]=" << dp[n][k] << endl;
            ans[k] = max(ans[k], dp[n][k]);
        }
    }

    rep1(k, N)
    {
        ans[k] = max(ans[k], ans[k - 1]);
        cout << ans[k] << endl;
    }

    return 0;
}