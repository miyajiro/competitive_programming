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

using S = ll; // 個数1以上の最小のindex。個数0しかないなら-1LL

S op(S a, S b){
    if(a == -1LL){
        return b;
    }
    if(b == -1LL){
        return a;
    }
    return min(a, b);
}

S e(){
    return -1LL;
}

ll N;
vl L, R, Xs, origL, origR;
vl Cap;

using T = pair<pair<ll, ll>, ll>; // ((R, L), id);


void solve(){
    cin >> N;
    L.clear();
    R.clear();
    Xs.clear();
    origL.clear();
    origR.clear();
    Cap.clear();
    rep(i, N){
        ll l, r;
        cin >> l >> r;
        L.eb(l);
        R.eb(++r);
        origL.eb(l);
        origR.eb(r);
        Xs.eb(l);
        Xs.eb(r);
    }
    sort(rng(Xs));
    uni(Xs);

    ll SIZE = sz(Xs) - 1; // 箱の数
    rep(xi, SIZE){
        Cap.eb(Xs[xi + 1] - Xs[xi]);
    }

    vector<T> tArray;
    rep(i, N){
        L[i] = lower_bound(rng(Xs), L[i]) - Xs.begin();
        R[i] = lower_bound(rng(Xs), R[i]) - Xs.begin();
        tArray.eb(T(LP(R[i], L[i]), i));
    }
    sort(rng(tArray));

    segtree<S, op, e> seg(SIZE);
    rep(i, SIZE){
        if(Cap[i] > 0){
            seg.set(i, i);
        } else {
            seg.set(i, -1LL);
        }
    }

    for(auto t : tArray){
        int i = t.sc;
        ll l = L[i];
        ll r = R[i];
        ll res = seg.prod(l, r);
        if(res == -1LL){
            cout << "No\n";
            return;
        }

        Cap[res]--;
        if(Cap[res] == 0){
            seg.set(res, -1LL);
        }
    }
    cout << "Yes\n";
}

void solve_()
{
    int t;
    cin >> t;
    rep(i, t){
        solve();
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve_();
    return 0;
}