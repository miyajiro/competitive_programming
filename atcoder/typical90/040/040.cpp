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

int N;
ll W;
vl A;
vv(ll) C;

void solve()
{
    cin >> N >> W;
    C = vv(ll)(N, vl());
    rep(ni, N){
        ll a;
        cin >> a;
        A.pb(a);
    }
    rep(ni, N){
        ll k;
        cin >> k;
        rep(ki, k){
            int c;
            cin >> c;
            c--;
            C[ni].pb(c);
        }
    }

    mf_graph<ll> graph(N + 2);

    ll ans = 0;
    ll s = N;
    ll t = N + 1;
    ll inf = 1e18;
    rep(ni, N){
        if(W < A[ni]){
            ans += A[ni] - W;
            graph.add_edge(s, ni, 0);
            graph.add_edge(ni, t, A[ni] - W);
        } else {
            graph.add_edge(s, ni, W - A[ni]);
            graph.add_edge(ni, t, 0);
        }

        for(auto c : C[ni]){
            graph.add_edge(ni, c, inf);
        }
    }

    ans -= graph.flow(s, t);

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