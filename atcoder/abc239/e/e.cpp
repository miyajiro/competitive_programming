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

int N;
vi X;
vi A, B;
int Q;
vi K;
vvi G;
vvi datb; // 拡頂点の部分木の数字を大きい順に格納(20番目まで)
vi V;

vi dfs(int now, int from){
    priority_queue<int> q;
    q.push(X[now]);

    for(auto nex : G[now]){
        if(nex == from){
            continue;
        }

        vi res = dfs(nex, now);
        for(auto e : res){
            q.push(e);
        }
    }

    while(!q.empty() && sz(datb[now]) < 20){
        datb[now].eb(q.top());
        q.pop();
    }

    return datb[now];
}

void solve()
{
    cin >> N >> Q;
    G = vvi(N);
    datb = vvi(N);
    rep(i, N){
        int x;
        cin >> x;
        X.eb(x);
    }
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        A.eb(--a);
        B.eb(--b);
        G[a].eb(b);
        G[b].eb(a);
    }

    dfs(0, -1);

    rep(i, Q){
        int v, k;
        cin >> v >> k;
        V.eb(--v);
        K.eb(--k);

        cout << datb[v][k] << "\n";
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