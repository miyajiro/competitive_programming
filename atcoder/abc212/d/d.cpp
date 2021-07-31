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

ll Q;
vi T;
vl X;
vl imosPlus;
priority_queue<LP, vector<LP>, greater<LP>> pq;

void solve()
{
    cin >> Q;
    imosPlus = vl(Q, 0);
    T = vi(Q, 0);
    X = vl(Q, 0LL);
    rep(qi, Q){
        int t;
        ll x;
        cin >> t;
        T[qi] = t;
        if(t == 1 || t == 2){
            cin >> x;
            X[qi] = x;
        }

        if(qi > 0){
            imosPlus[qi] = imosPlus[qi - 1];
        }

        if(t == 2){
            imosPlus[qi] += x;
        }
    }

    // rep(i, Q){
    //     show(i);
    //     show(imosPlus[i]);
    // }

    rep(qi, Q){
        int t = T[qi];
        if(t == 1){
            pq.push(LP(X[qi] - imosPlus[qi], qi));
        }
        if(t == 3){
            LP lp = pq.top();
            pq.pop();
            int xqi = lp.sc;
            ll x = X[xqi];
            ll d = imosPlus[qi] - imosPlus[xqi];
            // show(qi);
            // show(xqi);
            // show(x);
            // show(imosPlus[qi]);
            // show(imosPlus[xqi]);
            // show(d);
            cout << x + d << "\n";
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