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
using namespace atcoder;
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

ll _N;
vl A;
ll X;

const ll INF = 0xfffffffffffffff;

ll solve(ll N){ // N個選んだときの最大魔力。
    // cerr << "N" << N << endl;
    vv(ll) dp(N + 1, vl(N, -1LL)); // dp[i][k]: dp[i][k] i個選んで mod Nでkとなる場合、魔力がX以下の最大値。

    dp[0][0] = 0LL;
    rep(ai, _N){ // ai番目を利用する。
        rrep(i, N){ // i個選んだとき、i+1番目にaiを選ぶ。
            rep(k, N){ // i個選んでmodがkのときを更新。
                if(dp[i][k] == -1LL){
                    continue;
                }
                ll update = A[ai] + dp[i][k];
                if(update > X){
                    continue;
                }
                ll newK = update % N;
                chmax(dp[i+1][newK], update);
            }
        }
    }

    // rep(i, N+1){
    //     rep(k, N){
    //         cerr << "dp[" << i << "][" << k << "]=" << dp[i][k] << endl;
    //     }
    // }

    if(dp[N][X % N] == -1LL){
        return INF;
    }
    return (X - dp[N][X % N]) / N;
}

int main()
{
    cin >> _N >> X;
    rep(i, _N){
        ll a;
        cin >> a;
        A.pb(a);
    }

    ll ans = INF;
    rep1(i, _N){
        chmin(ans, solve(i));
    }

    cout << ans << endl;

    return 0;
}