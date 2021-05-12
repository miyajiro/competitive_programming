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

ll N;
vl _D, _C, _S, D, C, S;
v(LP) D_INDEX;

vv(ll) dp(5001, vl(5001, 0));

int main()
{
    cin >> N;
    rep(i, N){
        ll d, c, s;
        cin >> d >> c >> s;
        _D.pb(d);
        _C.pb(c);
        _S.pb(s);
        D_INDEX.pb(LP(d, i));
    }
    sort(rng(D_INDEX));

    D.pb(0);
    C.pb(0);
    S.pb(0);

    rep(i, N){
        ll sortI = D_INDEX[i].sc;
        D.pb(_D[sortI]);
        C.pb(_C[sortI]);
        S.pb(_S[sortI]);
    }

    rep1(wi, N){
        rep1(t, 5000){
            chmax(dp[wi][t], dp[wi][t-1]);
            chmax(dp[wi][t], dp[wi-1][t]);
            if(t <= D[wi] && t - C[wi] >= 0){
                chmax(dp[wi][t], dp[wi-1][t - C[wi]] + S[wi]);
            }
        }
    }


    cout << dp[N][5000] << endl;

    return 0;
}