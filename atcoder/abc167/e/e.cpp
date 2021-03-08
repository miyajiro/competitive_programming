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
using MOD = modint998244353;

int main()
{
    ll N;
    ll m;
    MOD M;
    ll K;
    cin >> N >> m >> K;
    M = m;
    vv(MOD) dp(2, v(MOD)(K+1, 0)); // dp[pos][i]: i組同じ色で塗ったときの塗り方

    int pos = 0;
    int past = 1;

    rep(i, N){
        if(i == 0){
            dp[pos][0] = M;
        } else {
            rep(k, K + 1){ // dp[p][k]から更新
                dp[pos][k] += dp[past][k] * (M - 1);
                if(k < K){
                    dp[pos][k + 1] += dp[past][k];
                }
            }
        }
        swap(pos, past);
    }

    MOD ans = 0;

    rep(i, K+1){
        ans += dp[past][i];
    }
    cout << ans.val() << endl;

    return 0;
}