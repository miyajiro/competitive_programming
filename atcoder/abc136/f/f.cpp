#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
#define show(x) cout << #x << " = " << x << endl;
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

vl Xs, Ys;
vl X, Y;
ll N;
vp points;

void solve()
{
    cin >> N;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
        Xs.pb(x);
        Ys.pb(y);
    }

    sort(rng(Xs));
    uni(Xs);
    sort(rng(Ys));
    uni(Ys);

    fenwick_tree<ll> fwL(sz(Ys)), fwR(sz(Ys));

    rep(i, N){
        X[i] = lower_bound(rng(Xs), X[i]) - Xs.begin();
        Y[i] = lower_bound(rng(Ys), Y[i]) - Ys.begin();
        points.pb(P(X[i], Y[i]));

        fwR.add(Y[i], 1);
    }

    sort(rng(points));

    mint ans = 0;
    mint m2 = 2;

    for(auto p : points){
        int x = p.fr;
        int y = p.sc;

        fwL.add(y, 1);

        ll ld = fwL.sum(0, y);
        ll lu = fwL.sum(y + 1, sz(Ys));
        ll rd = fwR.sum(0, y);
        ll ru = fwR.sum(y + 1, sz(Ys));

        ans += m2.pow(N - 1); // 点が含まれる場合
        ans += (m2.pow(lu) - 1) * (m2.pow(rd) - 1) * m2.pow(ld) * m2.pow(ru);
        ans += (m2.pow(ld) - 1) * (m2.pow(ru) - 1) * m2.pow(rd) * m2.pow(lu);
        ans -= (m2.pow(ld) - 1) * (m2.pow(ru) - 1) * (m2.pow(lu) - 1) * (m2.pow(rd) - 1);

        fwR.add(y, -1);
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