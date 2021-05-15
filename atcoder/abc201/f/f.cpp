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
// using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
// using vp = vector<P>;
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
vl P, A, B, C;
vl sumA, sumAB, sumAC;
ll pos[200000];
ll dp[200000];

ll op(ll a, ll b){
    return min(a, b);
}

ll e(){
    return 0xfffffffffffffff;
}

void solve()
{
    cin >> N;
    rep(i, N){
        ll p;
        cin >> p;
        p--;
        P.pb(p);
        pos[p] = i;
    }

    segtree<ll, op, e> seg(N);

    rep(i, N){
        ll a, b, c, ab, ac;
        cin >> a >> b >> c;
        ab = min(a, b);
        ac = min(a, c);
        A.pb(a);
        B.pb(b);
        C.pb(c);
        if(i == 0){
            sumA.pb(a);
            sumAB.pb(ab);
            sumAC.pb(ac);
            continue;
        }
        sumA.pb(a + sumA[i - 1]);
        sumAB.pb(ab + sumAB[i - 1]);
        sumAC.pb(ac + sumAC[i - 1]);
    }

    rep(x, N){
        if(x == 0){
            dp[x] = 0;
        } else {
            dp[x] = sumAB[x - 1];
            chmin(dp[x], seg.prod(0, pos[x]) + sumA[x - 1]);
        }
        seg.set(pos[x], dp[x] - sumA[x]);
    }

    ll ans = e();
    rep(x, N){
        chmin(ans, dp[x] + (sumAC[N - 1] - sumAC[x]));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}