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

struct S{
    int sum;
    int width;
};

S op(S a, S b){
    return S{a.sum + b.sum, a.width + b.width};
}

S e(){
    return S{0, 0};
}

using F = bool;

S mapping(F f, S x){
    if(f){
        return S{x.width, x.width};
    } else {
        return x;
    }
}
F composition(F f, F g){
    return g || f;
}

F id(){
    return false;
}

int N, M;
using G = pair<int, P>;
vi L, R, X;
vector<G> RLX;

void solve()
{
    cin >> N >> M;
    rep(i, M){
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        RLX.eb(G(r, P(l, x)));
    }
    sort(rng(RLX));
    rep(i, M){
        R.eb(RLX[i].fr);
        L.eb(RLX[i].sc.fr);
        X.eb(RLX[i].sc.sc);
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    rep(i, N){
        seg.set(i, S{0, 1});
    }

    rep(i, M){
        int l = L[i];
        int r = R[i];
        int x = X[i];

        if(seg.prod(l, r).sum >= x){ // 超えてる
            continue;
        }

        int low = l; // [low, r)を埋めれば条件を満たす
        int high = r; // [high, r)を埋めても条件を満たさない.
        int mid;

        while(high - low > 1){
            mid = (high + low) / 2;

            if(seg.prod(l, mid).sum + seg.prod(mid, r).width >= x){
                low = mid;
            } else {
                high = mid;
            }
        }

        seg.apply(low, r, true);
    }
    rep(i, N){
        cout << seg.get(i).sum;
        if(i == N - 1){
            cout << "\n";
        } else {
            cout << " ";
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