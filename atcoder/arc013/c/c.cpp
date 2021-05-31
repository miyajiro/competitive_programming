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

int N;
vi X, Y, Z, M;
vi hxMin, hxMax, hyMin, hyMax, hzMin, hzMax;
vvi HXArray, HYArray, HZArray;
vi game;

void solve()
{
    cin >> N;
    HXArray = vvi(N);
    HYArray = vvi(N);
    HZArray = vvi(N);
    rep(i, N){
        int x, y, z;
        cin >> x >> y >> z;
        X.pb(x);
        Y.pb(y);
        Z.pb(z);
        int m;
        cin >> m;
        M.pb(m);
        rep(j, m){
            int hx, hy, hz;
            cin >> hx >> hy >> hz;
            HXArray[i].pb(hx);
            HYArray[i].pb(hy);
            HZArray[i].pb(hz);
        }
        hxMin.pb(*min_element(rng(HXArray[i])));
        hxMax.pb(*max_element(rng(HXArray[i])));
        hyMin.pb(*min_element(rng(HYArray[i])));
        hyMax.pb(*max_element(rng(HYArray[i])));
        hzMin.pb(*min_element(rng(HZArray[i])));
        hzMax.pb(*max_element(rng(HZArray[i])));
    }

    rep(i, N){
        game.pb(hxMin[i]);
        game.pb(X[i] - hxMax[i] - 1);
        game.pb(hyMin[i]);
        game.pb(Y[i] - hyMax[i] - 1);
        game.pb(hzMin[i]);
        game.pb(Z[i] - hzMax[i] - 1);
    }

    int grundy = 0;
    for(auto g : game){
        grundy ^= g;
    }

    if(grundy == 0){
        puts("LOSE");
    } else {
        puts("WIN");
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