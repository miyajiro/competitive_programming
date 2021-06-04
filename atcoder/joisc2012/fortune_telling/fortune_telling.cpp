#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
#include <atcoder/lazysegtree>
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

struct S{
    ll val;
    ll size;
};

S op(S a, S b){
    return S{a.val + b.val, a.size + b.size};
}

S e(){
    return S{0, 0};
}

using F = bool;

S mapping(F f, S x){
    if(!f){
        return x;
    }
    return S{x.size - x.val, x.size};
}

F composition(F f, F g){
    return f != g;
}

F id(){
    return false;
}

ll H, W;
ll K;
vl A, B, C, D;
vl Ys, Xs;
vvl x2QueryIdsL, x2QueryIdsR;

void input(){
    cin >> H >> W >> K;
    rep(i, K){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        A.pb(--a);
        B.pb(b);
        C.pb(--c);
        D.pb(d);
        Ys.pb(a);
        Ys.pb(b);
        Xs.pb(c);
        Xs.pb(d);
    }
    Ys.pb(0);
    Ys.pb(H);
    Xs.pb(0);
    Xs.pb(W);
}

void compress(){
    sort(rng(Ys));
    uni(Ys);
    sort(rng(Xs));
    uni(Xs);

    rep(k, K){
        A[k] = lower_bound(rng(Ys), A[k]) - Ys.begin();
        B[k] = lower_bound(rng(Ys), B[k]) - Ys.begin();
        C[k] = lower_bound(rng(Xs), C[k]) - Xs.begin();
        D[k] = lower_bound(rng(Xs), D[k]) - Xs.begin();
    }

    H = sz(Ys);
    W = sz(Xs);
}

void solve()
{
    input();
    compress();

    x2QueryIdsL = vvl(W);
    x2QueryIdsR = vvl(W);

    rep(queryId, K){
        x2QueryIdsL[C[queryId]].pb(queryId);
        x2QueryIdsR[D[queryId]].pb(queryId);
    }

    vector<S> initSeg;
    rep(i, H - 1){
        initSeg.pb(S{Ys[i + 1] - Ys[i], Ys[i + 1] - Ys[i]});
    }
    initSeg.pb(S{0, 0});

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(initSeg);

    ll ans = 0;

    rep(w, W){
        for(auto queryIdR : x2QueryIdsR[w]){
            seg.apply(A[queryIdR], B[queryIdR], true);
        }
        for(auto queryIdL : x2QueryIdsL[w]){
            seg.apply(A[queryIdL], B[queryIdL], true);
        }

        ll tate = seg.all_prod().val;
        ll yoko = (w == W - 1 ? 0 : (Xs[w + 1] - Xs[w]));

        ans += tate * yoko;
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