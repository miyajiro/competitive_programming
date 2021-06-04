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

using S = ll;
S op(S a, S b){
    return a + b;
}
S e(){
    return 0;
}
using F = bool;
S mapping(F f, S x){
    if(f){
        return 0;
    }
    return x;
}
F composition(F f, F g){
    return (f || g);
}
F id(){
    return false;
}

ll Q, K;
vl C, D, A, Ds, imosStocks;

void input(){
    cin >> Q >> K;
    rep(i, Q){
        ll c, d, a = 0;
        cin >> c >> d;
        if(c == 1LL){
            cin >> a;
        }
        C.pb(c);
        D.pb(d);
        Ds.pb(d);
        A.pb(a);
    }
}

void compress(){
    sort(rng(Ds));
    uni(Ds);
    rep(i, sz(D)){
        D[i] = lower_bound(rng(Ds), D[i]) - Ds.begin();
    }
}

void solve()
{
    input();
    compress();
    vector<S> initialSeg;
    rep(i, sz(Ds)){
        if(i == 0){
            imosStocks.pb(Ds[0] * K);
            initialSeg.pb(Ds[0] * K);
            continue;
        }
        imosStocks.pb((imosStocks[i - 1] + Ds[i]) * K);
        initialSeg.pb((Ds[i] - Ds[i-1]) * K);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(initialSeg);

    rep(qi, Q){
        int a = A[qi];
        int c = C[qi];
        int d = D[qi];
        if(c == 1LL){
            int l = -1, r = d + 1; // [r, d]を0にして、lは必要な分減らす
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(seg.prod(mid, d + 1) <= a){
                    r = mid;
                } else {
                    l = mid;
                }
            }
            a -= seg.prod(r, d + 1);
            if(l == -1){
                continue;
            }
            seg.set(l, seg.get(l) - a);
        } else {
            cout << imosStocks[d] - seg.prod(0, d + 1) << "\n";
        }
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