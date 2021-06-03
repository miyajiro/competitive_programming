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
// using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
// using vp = vector<P>;
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

ll N, M, K;
vl Ks;
vl A, B;
vl P, Q, R;
vl ans;
vvl station2QueryIds, station2TyphoonIdsL, station2TyphoonIdsR;

void input(){
    cin >> N >> M >> K;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        A.pb(--a);
        B.pb(b);
    }
    rep(m, M){
        ll p, q, r;
        cin >> p >> q >> r;
        P.pb(--p);
        Q.pb(--q);
        R.pb(r);
    }
}

void compress(){
    for(auto a : A){
        Ks.pb(a);
    }
    for(auto b : B){
        Ks.pb(b);
    }
    for(auto p : P){
        Ks.pb(p);
    }
    sort(rng(Ks));
    uni(Ks);
    rep(i, N){
        A[i] = lower_bound(rng(Ks), A[i]) - Ks.begin();
        B[i] = lower_bound(rng(Ks), B[i]) - Ks.begin();
    }
    rep(i, M){
        P[i] = lower_bound(rng(Ks), P[i]) - Ks.begin();
    }
    K = sz(Ks);
}

void solve()
{
    input();
    compress();

    ans = vl(M, -1LL);
    station2QueryIds = vvl(K);
    station2TyphoonIdsL = vvl(K);
    station2TyphoonIdsR = vvl(K);

    rep(m, M){
        station2QueryIds[P[m]].pb(m);
    }

    rep(n, N){
        station2TyphoonIdsL[A[n]].pb(n);
        station2TyphoonIdsR[B[n]].pb(n);
    }

    fenwick_tree<ll> fwt(N);

    rep(stationId, K){
        for(auto typhoonIdR : station2TyphoonIdsR[stationId]){
            fwt.add(typhoonIdR, -1LL);
        }
        for(auto typhoonIdL : station2TyphoonIdsL[stationId]){
            fwt.add(typhoonIdL, 1LL);
        }

        for(auto queryId : station2QueryIds[stationId]){
            int tL = Q[queryId];
            int tR = R[queryId];
            ans[queryId] = fwt.sum(tL, tR);
        }
    }

    for(auto a : ans){
        cout << a << "\n";
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