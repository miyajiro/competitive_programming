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

struct greateR
{
    template <class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

ll N, K, w0, w1, w2, w3;
ll N0, N1, N2, N3;

vl W, V;
vl W0_V, W1_V, W2_V, W3_V;
vl W0_V_SUM, W1_V_SUM, W2_V_SUM, W3_V_SUM;

priority_queue<LP> pq; // fr: val, sc: -w

int main()
{
    cin >> N >> K;
    rep(i, N)
    {
        ll w, v;
        cin >> w >> v;
        W.pb(w);
        V.pb(v);
        ll d = w - W[0];
        if (d == 0LL)
        {
            W0_V.pb(v);
        }
        else if (d == 1LL)
        {
            W1_V.pb(v);
        }
        else if (d == 2LL)
        {
            W2_V.pb(v);
        }
        else
        {
            W3_V.pb(v);
        }
    }
    w0 = W[0];
    w1 = w0 + 1LL;
    w2 = w0 + 2LL;
    w3 = w0 + 3LL;

    sort(rng(W0_V), greateR());
    sort(rng(W1_V), greateR());
    sort(rng(W2_V), greateR());
    sort(rng(W3_V), greateR());

    N0 = W0_V.size();
    N1 = W1_V.size();
    N2 = W2_V.size();
    N3 = W3_V.size();

    W0_V_SUM.pb(0LL);
    W1_V_SUM.pb(0LL);
    W2_V_SUM.pb(0LL);
    W3_V_SUM.pb(0LL);

    rep(i, N0)
    {
        W0_V_SUM.pb(W0_V_SUM[i] + W0_V[i]);
    }

    rep(i, N1)
    {
        W1_V_SUM.pb(W1_V_SUM[i] + W1_V[i]);
    }

    rep(i, N2)
    {
        W2_V_SUM.pb(W2_V_SUM[i] + W2_V[i]);
    }

    rep(i, N3)
    {
        W3_V_SUM.pb(W3_V_SUM[i] + W3_V[i]);
    }

    ll ans = 0;

    rep(n0, min(N0, K / w0) + 1)
    {
        ll freeSpace0 = K - n0 * w0;
        rep(n1, min(N1, freeSpace0 / w1) + 1)
        {
            ll freeSpace1 = freeSpace0 - n1 * w1;
            rep(n2, min(N2, freeSpace1 / w2) + 1)
            {
                ll freeSpace2 = freeSpace1 - n2 * w2;
                ll n3 = min(N3, freeSpace2 / w3);
                chmax(ans, W0_V_SUM[n0] + W1_V_SUM[n1] + W2_V_SUM[n2] + W3_V_SUM[n3]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}