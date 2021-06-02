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
#include <atcoder/maxflow>
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
vi X, Y, Z;
vi W;
map<int, int> w2I;
int mfgSize;

void solve()
{
    cin >> N;
    rep(i, N){
        int x, y, z;
        cin >> x >> y >> z;
        rep1(subX, x / 2){
            W.pb(subX * y * z);
            W.pb((x - subX) * y * z);
        }
        rep1(subY, y / 2){
            W.pb(subY * x * z);
            W.pb((y - subY) * x * z);
        }
        rep1(subZ, z / 2){
            W.pb(subZ * y * x);
            W.pb((z - subZ) * y * x);
        }
        X.pb(x);
        Y.pb(y);
        Z.pb(z);
    }

    sort(rng(W));
    uni(W);

    int szW = sz(W);
    // show(szW);
    mfgSize = szW * 2 + 2;
    mf_graph<int> mfg(mfgSize);

    int s = szW * 2;
    int t = s + 1;

    rep(i, szW){
        w2I[W[i]] = i;
        mfg.add_edge(s, i, 1);
        mfg.add_edge(szW + i, t, 1);
    }

    rep(i, N){
        int x = X[i];
        int y = Y[i];
        int z = Z[i];

        rep1(subX, x / 2){
            int wi1 = w2I[subX * y * z];
            int wi2 = w2I[(x - subX) * y * z];
            mfg.add_edge(wi1, szW + wi2, 1);
            mfg.add_edge(wi2, szW + wi1, 1);
        }
        rep1(subY, y / 2){
            int wi1 = w2I[subY * x * z];
            int wi2 = w2I[(y - subY) * x * z];
            mfg.add_edge(wi1, szW + wi2, 1);
            mfg.add_edge(wi2, szW + wi1, 1);
        }
        rep1(subZ, z / 2){
            int wi1 = w2I[subZ * y * x];
            int wi2 = w2I[(z - subZ) * y * x];
            mfg.add_edge(wi1, szW + wi2, 1);
            mfg.add_edge(wi2, szW + wi1, 1);
        }
    }

    int flow = mfg.flow(s, t);
    cout << flow + 2 * (szW - flow) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}