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

int N;
map<LP, int> mp;
ll T;
vl AX, AY, BX, BY;
ll dx[8] = {1, 1, 0, -1LL, -1LL, -1LL, 0, 1};
ll dy[8] = {0, 1, 1, 1, 0, -1LL, -1LL, -1LL};

void solve()
{
    vi from, to;
    cin >> N >> T;

    rep(i, 8){
        dx[i] *= T;
        dy[i] *= T;
    }

    rep(i, N){
        ll ax, ay;
        cin >> ax >> ay;
        AX.pb(ax);
        AY.pb(ay);
    }

    rep(i, N){
        ll bx, by;
        cin >> bx >> by;
        BX.pb(bx);
        BY.pb(by);
        mp[LP(bx, by)] = i;
    }

    int fN = N * 2 + 2;
    int s = fN - 2;
    int t = fN - 1;
    mf_graph<int> mf(fN);
    rep(i, N){
        mf.add_edge(s, i, 1);
        mf.add_edge(N + i, t, 1);
    }

    rep(ni, N){
        rep(di, 8){
            int nx = AX[ni] + dx[di];
            int ny = AY[ni] + dy[di];
            auto ite = mp.find(LP(nx, ny));
            if(ite != mp.end()){
                int ni2 = ite->sc;
                mf.add_edge(ni, ni2 + N, 1);
            }
        }
    }

    if(mf.flow(s, t) < N){
        cout << "No\n";
        return;
    }


    vi ans(N);

    for(auto edge : mf.edges()){
        if(edge.from == s || edge.to == t || edge.flow == 0){
            continue;
        }

        int ni1 = edge.from;
        int ni2 = edge.to - N;

        ll DX = BX[ni2] - AX[ni1];
        ll DY = BY[ni2] - AY[ni1];
        rep(di, 8){
            if(DX == dx[di] && DY == dy[di]){
                ans[ni1] = di + 1;
            }
        }
    }

    cout << "Yes\n";
    rep(i, N){
        cout << ans[i] << (i != N - 1 ? " " : "\n");
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