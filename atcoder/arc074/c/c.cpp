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


LP calc(ll H, ll W){ // 小さいピース、大きいピースを返す
    LP lp1 = LP(0, 0xffffffffff);
    LP lp2 = LP(0, 0xffffffffff);

    if(H >= 2LL){
        ll H2 = H / 2LL;
        lp1.fr = H2 * W;
        lp1.sc = (H - H2) * W;
    }
    if(W >= 2LL){
        ll W2 = W / 2LL;
        lp2.fr = W2 * H;
        lp2.sc = (W - W2) * H;
    }

    if((lp1.sc - lp1.fr) < (lp2.sc - lp2.fr)){
        return lp1;
    }
    return lp2;
}

void solve()
{
    ll H, W;
    cin >> H >> W;
    ll ans = 0xffffffffff;
    rep1(h, H - 1){
        ll s1 = W * h;
        LP lp = calc(H - h, W);
        chmin(ans, max(abs(s1 - lp.fr), abs(s1 - lp.sc)));
    }
    rep1(w, W - 1){
        ll s1 = w * H;
        LP lp = calc(H, W - w);
        chmin(ans, max(abs(s1 - lp.fr), abs(s1 - lp.sc)));
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}