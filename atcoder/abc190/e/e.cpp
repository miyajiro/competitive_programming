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

const ll INF = 0xfffffffffffff;
ll N, M;
vl A, B;
ll K;
vl C;
vv(ll) dist;        // dist[ci][ni] ciからniへの距離。
vv(ll) D;           // D[ci][ci] ciからciへの最短距離。
vv(ll) tonariArray; // tonariArray[ni][j] niからreachableな魔法石のj番目

string strBit(int n)
{
    string s;
    rep(i, 3)
    {
        if (n % 2 == 1)
        {
            s = "1" + s;
        }
        else
        {
            s = "0" + s;
        }
        n = n / 2;
    }
    return s;
}

int main()
{
    cin >> N >> M;
    rep(i, N)
    {
        tonariArray.pb(vl());
    }

    rep(i, M)
    {
        ll a, b;

        cin >> a >> b;
        a--;
        b--;
        A.pb(a);
        B.pb(b);
        tonariArray[a].pb(b);
        tonariArray[b].pb(a);
    }

    cin >> K;
    rep(i, K)
    {
        ll c;
        cin >> c;
        c--;
        C.pb(c);
        dist.pb(vl(N, INF));
        D.pb(vl(K, INF));

        dist[i][C[i]] = 0LL;
        D[i][i] = 0LL;

        queue<int> q; // nodeNum
        q.push(C[i]);

        while (!q.empty())
        {
            int ni = q.front();
            q.pop();
            rep(ti, tonariArray[ni].size())
            {
                int tonari = tonariArray[ni][ti];
                if (dist[i][ni] + 1LL < dist[i][tonari])
                {
                    dist[i][tonari] = dist[i][ni] + 1LL;
                    q.push(tonari);
                }
            }
        }
    }

    rep(ci1, K)
    {
        rep(ci2, K)
        {
            D[ci1][ci2] = dist[ci1][C[ci2]];
        }
    }

    ll ans = INF;

    rep(start, K)
    { // startから始まって
        // cerr << "start = " << start << endl;
        vv(ll) dp(1 << K, vl(K, INF)); // dp[s][ci] 集合sを訪れていて、最後にciを訪れたときの最小コスト
        dp[1 << start][start] = 0LL;
        rep(s, 1 << K)
        {
            rep(ci, K)
            {
                if (dp[s][ci] == INF)
                {
                    // cerr << "dp[" << strBit(s) << "][" << ci << "]=INF" << endl;
                    continue;
                }
                // cerr << "dp[" << strBit(s) << "][" << ci << "]=" << dp[s][ci] << endl;

                rep(nci, K)
                { // 新しく集合に加えるもの。
                    if ((s >> nci) % 2 == 1)
                        continue;

                    int ns = (s | (1 << nci));
                    // cerr << "ns = " << strBit(ns) << endl;
                    // cerr << "ci=" << ci << " nci=" << nci << endl;
                    // cerr << dp[s][ci] << endl;
                    // cerr << D[ci][nci] << endl;
                    chmin(dp[ns][nci], dp[s][ci] + D[ci][nci]);
                }
            }
        }

        rep(i, K)
        {
            chmin(ans, dp[bn(K)][i]);
        }
    }

    if (ans == INF)
        ans = -2LL;
    cout << ans + 1LL << endl;

    return 0;
}