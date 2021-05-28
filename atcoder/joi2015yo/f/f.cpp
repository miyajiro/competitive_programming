#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
#include <atcoder/segtree>
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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

#define None 0
#define Bruno 1
#define Anna 2

const ll INF = 0xffffffffffffff;

// ↓segtree
using S = ll;
S op(S a, S b){
    return max(a, b);
}
S e(){
    return -INF;
}
// ↑segtree

int N;
ll D;
vl X, Y;

vector<LP> xDiffAndYDiff1;
vector<LP> xDiffAndYDiff2;

map<ll, int> xDiffToCXDiff;
ll pow3[16];
ll cxDiff1ToMaxY[20000000];
bool cxDiff1IsAlreadySet[20000000];

int check(ll s, int i){
    return (s / pow3[i]) % 3LL;
}

void solve()
{
    cin >> N >> D;
    int N1 = N / 2;
    int N2 = N - N1;

    pow3[0] = 1LL;
    rep(i, 15){
        pow3[i + 1] = pow3[i] * 3LL;
    }

    xDiffAndYDiff1 = vector<LP>(pow3[N1]);
    xDiffAndYDiff2 = vector<LP>(pow3[N2]);

    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }

    xDiffAndYDiff1[0] = LP(0, 0);
    rep(n1, N1){
        rep(baseS, pow3[n1]){
            int s1Bruno = Bruno * pow3[n1] + baseS;
            int s1Anna = Anna * pow3[n1] + baseS;

            xDiffAndYDiff1[s1Bruno] = LP(xDiffAndYDiff1[baseS].fr + X[n1], xDiffAndYDiff1[baseS].sc + Y[n1]);
            xDiffAndYDiff1[s1Anna] = LP(xDiffAndYDiff1[baseS].fr - X[n1], xDiffAndYDiff1[baseS].sc - Y[n1]);
        }
    }

    xDiffAndYDiff2[0] = LP(0, 0);
    rep(n2, N2){
        rep(baseS, pow3[n2]){
            int s2Bruno = Bruno * pow3[n2] + baseS;
            int s2Anna = Anna * pow3[n2] + baseS;

            xDiffAndYDiff2[s2Bruno] = LP(xDiffAndYDiff2[baseS].fr + X[N1 + n2], xDiffAndYDiff2[baseS].sc + Y[N1 + n2]);
            xDiffAndYDiff2[s2Anna] = LP(xDiffAndYDiff2[baseS].fr - X[N1 + n2], xDiffAndYDiff2[baseS].sc - Y[N1 + n2]);
        }
    }

    sort(rng(xDiffAndYDiff1));

    vector<ll> xDiff1;
    vector<ll> yDiff1;
    for(auto lp : xDiffAndYDiff1){
        xDiff1.pb(lp.fr);
        yDiff1.pb(lp.sc);
    }

    segtree<S, op, e> seg(yDiff1);

    ll ans = -INF;

    rep(i2, sz(xDiffAndYDiff2)){
        ll xDiff2 = xDiffAndYDiff2[i2].fr;
        ll yDiff2 = xDiffAndYDiff2[i2].sc;

        ll minXDiff1 = -D - xDiff2;
        ll maxXDiff1 = D - xDiff2;

        int l = lower_bound(rng(xDiff1), minXDiff1) - xDiff1.begin();
        int r = upper_bound(rng(xDiff1), maxXDiff1) - xDiff1.begin();

        chmax(ans, seg.prod(l, r) + yDiff2);
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