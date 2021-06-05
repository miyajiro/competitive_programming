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

#define COLD 0
#define HOT 1
#define COMFORT -1

const ll INF = 0xffffffffffff;
using S = pair<LP, LP>;

PQ(S) pq; // dist, N, temp, X
ll N, M, X;
vl T;
vl A, B, D;
vector<vvl> dp;
struct edge{
    ll to;
    ll cost;
};
vector<vector<edge>> edges;

// dp[N][temp][x]; // 部屋Nにおり、tempな状態があとx分で解除される。

void input(){
    cin >> N >> M >> X;
    dp = vector<vvl>(N, vvl(2, vl(X + 1, INF)));
    edges = vector<vector<edge>>(N);
    rep(i, N){
        ll t;
        cin >> t;
        if(t == 0){
            t = COLD;
        } else if(t == 1){
            t = COMFORT;
        } else if(t == 2){
            t = HOT;
        }
        T.pb(t);
    }
    rep(i, M){
        ll a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        edges[a].pb(edge{b, d});
        edges[b].pb(edge{a, d});
    }
}

void solve()
{
    input();
        // pq: dist, N, temp, X
    dp[0][COLD][X] = 0;
    pq.push(S(LP(0, 0), LP(COLD, X)));

    while(!pq.empty()){
        S s = pq.top();
        pq.pop();
        ll dist = s.fr.fr;
        ll node = s.fr.sc;
        ll temp = s.sc.fr;
        ll x = s.sc.sc;
        if(dist > dp[node][temp][x]){
            continue;
        }

        for(auto edge : edges[node]){
            ll newNode = edge.to;
            ll destTemp = T[newNode];
            ll newX = max(0LL, x - edge.cost);
            ll newTemp = temp;

            if(newX > 0 && destTemp != COMFORT && temp != destTemp){ // 温度が合わないときは無理
                continue;
            }

            if(destTemp != COMFORT){ // 快適じゃないときは絶対これ
                newTemp = destTemp;
                newX = X;
            }

            if(chmin(dp[newNode][newTemp][newX], dist + edge.cost)){
                pq.push(S(LP(dp[newNode][newTemp][newX], newNode), LP(newTemp, newX)));
            }
        }
    }

    ll ans = INF;
    rep(x, X + 1){
        chmin(ans, dp[N-1][HOT][x]);
        chmin(ans, dp[N-1][COLD][x]);
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