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

vl chArray[200000];
ll N;
vl par;
ll Q;
vl U, D;

ll n2GoLabel[200000];
ll n2BackLabel[200000];
ll label2N[400000];
ll n2Depth[200000];
ll n2LeftCnt[200000]; // 自分未満に何個あるか

ll depth2Cnt[200000];
set<ll> depth2GoLabelSet[200000];

ll dfs(ll now, ll depth, ll label){
    // cerr << now << " " << depth << " " << label << "\n";

    n2Depth[now] = depth;
    n2LeftCnt[now] = depth2Cnt[depth];
    depth2Cnt[depth]++;
    n2GoLabel[now] = label;
    depth2GoLabelSet[depth].insert(label);
    label2N[label] = now;
    label++;

    for(auto ch : chArray[now]){
        label = dfs(ch, depth+1, label);
    }

    n2BackLabel[now] = label;
    label2N[label] = now;
    label++;

    return label;
}

ll calc(ll u, ll d){
    ll uDepth = n2Depth[u];

    if(uDepth > d){
        return 0;
    }

    if(uDepth == d){
        return 1;
    }

    auto iteL = depth2GoLabelSet[d].lower_bound(n2GoLabel[u]);
    if(iteL == depth2GoLabelSet[d].end() || ((*iteL) > n2BackLabel[u])){
        return 0;
    }

    auto iteR = depth2GoLabelSet[d].lower_bound(n2BackLabel[u]);
    ll lCnt, rCnt;
    ll lN = label2N[*iteL];
    lCnt = n2LeftCnt[lN];
    if(iteR == depth2GoLabelSet[d].end()) {
        rCnt = depth2Cnt[d];
    } else {
        ll rN = label2N[*iteR];
        rCnt = n2LeftCnt[rN];
    }
    return rCnt - lCnt;
}

void solve()
{
    cin >> N;
    rep1(i, N - 1){
        ll p;
        cin >> p;
        p--;
        par.pb(p);
        chArray[p].pb(i);
    }

    dfs(0, 0, 0);

    cin >> Q;
    rep(i, Q){
        ll u, d;
        cin >> u >> d;
        u--;
        cout << calc(u, d) << "\n";
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