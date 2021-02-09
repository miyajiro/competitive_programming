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

typedef pair<ll, LP> E;
vector<LP> toEdges;
v(E) edges;
vv(LP) es; // to, cost
ll N;
ll M;
vl A, B, C;
vl ans;
vv(ll) D;
const ll INF = 0xffffffffffff;

int main()
{
    cin >> N >> M;
    rep(i, N)
    {
        es.pb(v(LP)());
        ans.pb(INF);
        D.pb(vl());
        rep(j, N)
        {
            D[i].pb(INF);
        }
    }

    rep(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        edges.pb(E(c, LP(a, b)));
    }

    sort(edges.begin(), edges.end());

    ll newM = M;

    rep(i, M)
    {
        E e = edges[i];
        ll c = e.fr;
        ll a = e.sc.fr;
        ll b = e.sc.sc;

        if (D[a][b] != INF || (a == b && ans[a] != INF))
        {
            newM--;
            continue;
        }

        if (a == b)
        {
            ans[a] = c;
            newM--;
            continue;
        }
        es[a].pb(LP(b, c));

        A.pb(a);
        B.pb(b);
        C.pb(c);
    }

    M = newM;

    rep(i, N)
    {
        D[i][i] = 0;
    }

    rep(v, N)
    { // v中心ダイクストラ
        PQ(LP)
        pq;
        D[v][v] = 0;
        pq.push(LP(0, v));

        while (!pq.empty())
        {
            LP p = pq.top();
            pq.pop();
            if (p.fr > D[v][p.sc])
                continue;

            ll now = p.sc;

            rep(i, es[now].size())
            {
                LP e = es[now][i];

                ll to = e.fr;
                ll co = e.sc;
                if (D[v][to] > D[v][now] + co)
                {
                    D[v][to] = D[v][now] + co;
                    pq.push(LP(D[v][to], to));
                }
            }
        }
    }

    rep(i, N)
    {
        rep(j, N)
        {
            if (i != j)
                chmin(ans[i], D[i][j] + D[j][i]);
        }
        if (ans[i] == INF)
        {
            puts("-1");
        }
        else
        {
            cout << ans[i] << endl;
        }
    }

    return 0;
}