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

using S = pair<ll, P>; // cost, 駅, 花の本数
int N, M, K;
const ll INF = 0xffffffffffff;
vvl dp;
struct edge{
    int to;
    ll cost;
};
vector<vector<edge>> edges;
vi X;
vl Y;

void input(){
    cin >> N >> M >> K;
    edges = vector<vector<edge>>(N);
    dp = vvl(N, vl(K + 1, INF));
    rep(i, M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        edges[a].pb(edge{b, c});
        edges[b].pb(edge{a, c});
    }
    rep(i, N){
        int x;
        ll y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }
}

void solve()
{
    input();
    PQ(S) pq; // cost, station, honsu
    dp[0][0] = 0;
    pq.push(S(0, P(0, 0)));

    while(!pq.empty()){
        S s = pq.top();
        pq.pop();
        ll cost = s.fr;
        int node = s.sc.fr;
        int k = s.sc.sc;
        if(dp[node][k] < cost){
            continue;
        }

        // 花を買う場合
        for(int n = 1; X[node] > 0 && k + n * X[node] < K + X[node]; n++){
            int nextK = min(K, k + n * X[node]);
            if(chmin(dp[node][nextK], cost + n * Y[node])){
                pq.push(S(dp[node][nextK], P(node, nextK)));
            }
        }

        // 駅を移動する場合
        for(auto edge : edges[node]){
            if(chmin(dp[edge.to][k], cost + edge.cost)){
                pq.push(S(dp[edge.to][k], P(edge.to, k)));
            }
        }
    }

    ll ans = dp[N-1][K];
    if(ans == INF){
        ans = -1LL;
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