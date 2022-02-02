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

struct Node{
    int par; // 親のindex
    vi chs; // 子供達のindex
    ll fromPar; // 親からの自分含む遅延クエリ
    ll c; // 今の値
};

int N, Q;
vi A, B, T, E, X;
vvi G;
using Nodes = vector<Node>;
Nodes nodes;

void initNodesDfs(int now, int from){
    nodes[now].par = from;

    for(auto nex : G[now]){
        if(nex == from){
            continue;
        }
        nodes[now].chs.eb(nex);

        initNodesDfs(nex, now);
    }
}

void dfs(ll now, ll x){ // x降ってきた。
    nodes[now].fromPar += x; // 上から降ってきたものを加算
    nodes[now].c += nodes[now].fromPar;

    for(auto ch : nodes[now].chs){
        dfs(ch, nodes[now].fromPar);
    }

    nodes[now].fromPar = 0;
}

void solve()
{
    cin >> N;
    G = vvi(N);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        A.eb(--a);
        B.eb(--b);
        G[a].eb(b);
        G[b].eb(a);
    }
    nodes = Nodes(N, Node{-1, vi(), 0, 0});
    initNodesDfs(0, -1);

    cin >> Q;
    rep(i, Q){
        int t, e, x;
        cin >> t >> e >> x;
        T.eb(t);
        E.eb(--e);
        X.eb(x);

        int a = A[e];
        int b = B[e];

        if(t == 2){ // aから開始すると仮定、bを通らない
            swap(a, b);
        }

        if(nodes[a].par == b){ // aが子供の場合
            nodes[a].fromPar += x;
        } else { // aが親で、bが子供の場合
            nodes[0].fromPar += x;
            nodes[b].fromPar -= x;
        }
    }

    dfs(0, 0);

    for(auto node : nodes){
        cout << node.c << "\n";
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