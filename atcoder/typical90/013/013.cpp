#include <bits/stdc++.h>
#include <atcoder/all>
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
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using namespace atcoder;
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
ll M;
vl A, B, C;
const ll INF = 0xffffffffffffff;
vv(LP) toAndCostsArray(100001);

vl solve(ll s){
    vl d(N, INF);
    d[s] = 0;
    PQ(LP) pq;
    pq.push(LP(0, s));

    while(!pq.empty()){
        LP lp = pq.top();
        pq.pop();
        ll givenCost = lp.fr;
        ll n = lp.sc;
        if(givenCost > d[n]){
            continue;
        }

        for(auto toAndCost : toAndCostsArray[n]){
            ll to = toAndCost.fr;
            ll cost = toAndCost.sc;
            if(chmin(d[to], d[n] + cost)){
                pq.push(LP(d[to], to));
            }
        }
    }

    return d;
}

int main()
{
    cin >> N >> M;

    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        A.pb(a);
        B.pb(b);
        C.pb(c);
        toAndCostsArray[a].pb(LP(b, c));
        toAndCostsArray[b].pb(LP(a, c));
    }

    vl dFrom0 = solve(0);
    vl dFromN_1 = solve(N-1);

    rep(i, N){
        cout << dFrom0[i] + dFromN_1[i] << endl;
    }

    return 0;
}