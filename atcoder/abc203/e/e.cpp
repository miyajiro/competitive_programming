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

ll N;
ll _N;
ll M;
vl X, Y;
vl Xs;
ll _M;
vector<vl> xToPYArray;
const ll tableSize = 400002;
const ll newSY = 200001;
bool okTable[tableSize];

// (0, N)→(0, 200001)

void solve()
{
    cin >> N >> M;
    _M = M;

    rep(i, _M){
        ll x, y;
        cin >> x >> y;
        ll newY = y - N + newSY;
        if(newY < 0 || newY >= tableSize){
            M--;
            continue;
        }

        X.pb(x);
        Y.pb(newY);
        Xs.pb(x);
    }
    sort(rng(Xs));
    uni(Xs);
    xToPYArray = vector<vl>(sz(Xs));

    rep(i, M){
        X[i] = lower_bound(rng(Xs), X[i]) - Xs.begin();
        xToPYArray[X[i]].pb(Y[i]);

        // show(X[i]);
        // show(Y[i]);
    }

    okTable[newSY] = true;

    rep(x, sz(Xs)){
        sort(rng(xToPYArray[x]));

        vector<int> okPYArray = vi();
        vector<int> ngPYArray = vi();
        for(auto py : xToPYArray[x]){
            if((py > 0 && okTable[py - 1]) || (py < tableSize - 1 && okTable[py + 1])){
                okPYArray.pb(py);
            } else {
                ngPYArray.pb(py);
            }
        }

        for(auto okpy : okPYArray){
            okTable[okpy] = true;
        }
        for(auto ngpy : ngPYArray){
            okTable[ngpy] = false;
        }
    }

    int ans = 0;
    rep(i, tableSize){
        if(okTable[i]){
            ans++;
        }
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