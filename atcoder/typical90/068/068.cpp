#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

ll N, Q;
vl T, X, Y, V;
vl diff;
vl imos;
set<int> undefNum;

void solve()
{
    cin >> N >> Q;
    rep(i, N){
        undefNum.insert(i);
    }
    diff = vl(N, 0);
    rep(i, Q){
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        x--;
        y--;
        T.eb(t);
        X.eb(x);
        Y.eb(y);
        V.eb(v);

        if(t == 0){
            diff[x] = (x % 2 == 0 ? v : -v);
        }
    }

    rep(i, N){
        if(i == 0){
            imos.eb(diff[0]);
        } else {
            imos.eb(diff[i] + imos[i - 1]);
        }
    }

    rep(i, Q){
        int t = T[i];
        int x = X[i];
        int y = Y[i];
        int v = V[i];

        if(t == 0){
            undefNum.erase(x);
        } else {

            if(x == y){
                cout << v << "\n";
                continue;
            }

            int lbUndefNum = *(undefNum.lower_bound(min(x, y)));
            if(lbUndefNum < max(x, y)){
                cout << "Ambiguous\n";
                continue;
            }

            ll imosY = (y - 1 < 0) ? 0 : imos[y - 1];
            ll imosX = (x - 1 < 0) ? 0 : imos[x - 1];
            ll lastV = (abs(x - y) % 2 == 1) ? -v : v;
            ll tashi = (y % 2 == 1) ? imosY - imosX : imosX - imosY;

            cout << lastV + tashi << "\n";
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