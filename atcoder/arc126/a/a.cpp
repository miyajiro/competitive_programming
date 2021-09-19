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

void calc(){
    ll N2, N3, N4;
    cin >> N2 >> N3 >> N4;
    // 4 3 3
    // 2 2 3 3
    // 4 4 2
    // 4 2 2 2
    // 2 2 2 2 2
    ll ans = 0;

    ll cnt0 = min(N3 / 2, N4); // 334
    ans += cnt0;
    N3 -= cnt0 * 2LL;
    N4 -= cnt0;

    ll cnt1 = min(N3 / 2LL, N2 / 2LL); // 3322
    ans += cnt1;
    N3 -= cnt1 * 2LL;
    N2 -= cnt1 * 2LL;

    ll cnt2 = min(N4 / 2LL, N2);
    ans += cnt2;
    N4 -= cnt2 * 2LL;
    N2 -= cnt2;

    ll cnt3 = min(N4, N2 / 3LL);
    ans += cnt3;
    N4 -= cnt3;
    N2 -= 3 * cnt3;

    ll cnt4 = N2 / 5LL;
    ans += cnt4;

    cout << ans << "\n";
}

void solve()
{
    int T;
    cin >> T;
    rep(_, T){
        calc();
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