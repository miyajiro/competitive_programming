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

const ll INF = 0xfffffffffffffff;

ll N;
vl X, C;
map<ll, ll> cnt;
map<ll, ll> c2MaxX;
map<ll, ll> c2MinX;
set<ll> cnumset;
vl cnums; // unique
ll dp[200003][2];

ll labs(ll a){
    return a < 0 ? -a : a;
}

int main()
{
    cin >> N;
    X.pb(0);
    C.pb(0);
    cnumset.insert(0);
    c2MaxX[0] = -INF;
    c2MinX[0] = INF;

    rep(i, N){
        ll x, c;
        cin >> x >> c;
        X.pb(x);
        C.pb(c);
        cnumset.insert(c);
        c2MaxX[c] = -INF;
        c2MinX[c] = INF;
    }

    X.pb(0);
    C.pb(N+1);
    cnumset.insert(N+1);
    c2MaxX[N+1] = -INF;
    c2MinX[N+1] = INF;

    N+=2;

    for(auto c : cnumset){
        cnums.pb(c);
    }

    sort(rng(cnums));

    rep(i, N){
        chmax(c2MaxX[C[i]], X[i]);
        chmin(c2MinX[C[i]], X[i]);
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    rep1(i, cnums.size() - 1){ // dp[i]をdp[i-1]で更新する。C[i]
        ll pastc = cnums[i-1];
        ll pastMax = c2MaxX[pastc];
        ll pastMin = c2MinX[pastc];

        ll c = cnums[i];
        ll nextMax = c2MaxX[c];
        ll nextMin = c2MinX[c];

        dp[i][0] = min( // minに終わる
            dp[i-1][0] + labs(nextMax - pastMin) + labs(nextMin - nextMax), // minに始まりminに終わる
            dp[i-1][1] + labs(nextMax - pastMax) + labs(nextMin - nextMax) // maxに始まりminに終わる
        );

        dp[i][1] = min( // maxに終わる
            dp[i-1][0] + labs(nextMin - pastMin) + labs(nextMax - nextMin), // minに始まりmaxに終わる
            dp[i-1][1] + labs(nextMin - pastMax) + labs(nextMax - nextMin) // maxに始まりmaxに終わる
        );
    }

    cout << min(dp[cnums.size()-1][0], dp[cnums.size()-1][1]) << endl;

    return 0;
}