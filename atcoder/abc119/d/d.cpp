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

const ll INF = 0xfffffffffffffff;
int A, B, Q;
vl S, T, X;
vl S_Near, T_Near;

void solve()
{
    cin >> A >> B >> Q;

    S.eb(-INF);
    T.eb(-INF);
    rep(i, A){
        ll s;
        cin >> s;
        S.eb(s);
    }
    rep(i, B){
        ll t;
        cin >> t;
        T.eb(t);
    }
    S.eb(INF);
    T.eb(INF);

    A += 2;
    B += 2;

    S_Near = vl(A);
    T_Near = vl(B);

    srep(i, 1, A - 1){
        ll s = S[i];
        ll tri = lower_bound(rng(T), s) - T.begin();
        ll tli = tri - 1LL;

        // show(s);
        // show(T[tri]);
        // show(T[tli]);

        S_Near[i] = min(T[tri] - s, s - T[tli]);
        // show(S_Near[i]);
    }

    srep(i, 1, B - 1){
        ll t = T[i];
        ll sri = lower_bound(rng(S), t) - S.begin();
        ll sli = sri - 1LL;

        T_Near[i] = min(S[sri] - t, t - S[sli]);
        // show(T_Near[i]);
    }

    rep(i, Q){
        ll x;
        cin >> x;

        ll tri = lower_bound(rng(T), x) - T.begin();
        ll tli = tri - 1LL;

        ll sri = lower_bound(rng(S), x) - S.begin();
        ll sli = sri - 1LL;

        cout << min({abs(T[tri] - x) + T_Near[tri], abs(T[tli] - x) + T_Near[tli], abs(S[sri] - x) + S_Near[sri], abs(S[sli] - x) + S_Near[sli]}) << "\n";
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