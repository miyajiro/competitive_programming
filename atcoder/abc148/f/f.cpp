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

int N, T, A;
vi X, Y;
vvi G;
vi depth;
vector<bool> reachableT; // Tの祖先であり、Tから辿れるならtrue

bool dfs(int now, int prev, int dep){ // Tの祖先ならtrue
    bool isAncestorOfT = false;
    if(now == T){
        isAncestorOfT = true;
    }
    depth[now] = dep;

    for(auto nex : G[now]){
        if(nex == prev){
            continue;
        }

        isAncestorOfT = (dfs(nex, now, dep + 1) || isAncestorOfT);
    }

    if(isAncestorOfT && depth[now] > depth[T] / 2){
        reachableT[now] = true;
    }

    return isAncestorOfT;
}

int dfs2(int now){ // nowの子孫の最大深さを返す
    int res = depth[now];
    // show(now);
    // show(depth[now]);

    for(auto nex : G[now]){
        if(depth[nex] < depth[now]){
            continue;
        }

        chmax(res, dfs2(nex));
    }

    return res;
}


void solve()
{
    cin >> N >> T >> A;
    T--;
    A--;
    G = vvi(N);
    reachableT = vector<bool>(N, false);
    depth = vi(N, -1);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        G[--a].eb(--b);
        G[b].eb(a);
    }

    dfs(A, -1, 0);

    P p = P(0xfffffff, -1); // 最小深さ、最小深さの親

    rep(i, N){
        if(reachableT[i]){
            chmin(p, P(depth[i], i));
        }
    }

    int mid = p.sc;
    int goalD = dfs2(mid);

    int ans = goalD - 1;
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