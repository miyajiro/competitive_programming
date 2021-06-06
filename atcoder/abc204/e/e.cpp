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


const ll INF = INT64_MAX;
ll N, M;
struct E{
    ll to;
    ll cost;
    ll rash;
};
vector<vector<E>> edges;
vector<ll> dp;

void input(){
    cin >> N >> M;

    edges = vector<vector<E>>(N);
    rep(i, M){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;

        edges[a].pb(E{b, c, d});
        edges[b].pb(E{a, c, d});
    }
}

ll calcRash(ll d, ll t){
    return d / (t + 1LL);
}

ll calcBestTime(ll now, ll d){
    if(now >= d){
        return now;
    }

    ll sqrtD = floor(sqrt(d));
    ll t1 = max(sqrtD - 1, now);
    ll t2 = max(sqrtD, now);

    if(now + calcRash(d, now) > t1 + calcRash(d, t1)){
        now = t1;
    }
    if(now + calcRash(d, now) > t2 + calcRash(d, t2)){
        now = t2;
    }

    return now;
}

void solve()
{
    input();
    dp = vl(N, INF);
    PQ(LP) pq;

    dp[0] = 0;
    pq.push(LP(0, 0));

    while(!pq.empty()){
        LP lp = pq.top();
        pq.pop();
        ll dist = lp.fr;
        ll from = lp.sc;
        if(dp[from] < dist){
            continue;
        }

        for(auto edge : edges[from]){
            ll to = edge.to;
            ll cost = edge.cost;
            ll rash = edge.rash;

            ll departureTime = calcBestTime(dist, rash);
            if(chmin(dp[to], departureTime + cost + calcRash(rash, departureTime))){
                pq.push(LP(dp[to], to));
            }
        }
    }

    ll ans = dp[N-1];
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