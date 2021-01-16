#include <bits/stdc++.h>
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
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

const ll MOD = (1e+9) + 7;

ll factorial[200001];

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

ll comb(int n, int k)
{
    return (factorial[n] * modinv(factorial[k], MOD) % MOD) * modinv(factorial[n - k], MOD) % MOD;
}

int main()
{
    int H, W, K;

    cin >> H >> W >> K;

    factorial[0] = 1LL;
    rep1(i, 200001)
    {
        factorial[i] = (ll(i) * factorial[i - 1]) % MOD;
    }

    ll fixed2KomaCost = 0;

    rep(dx, W)
    {
        fixed2KomaCost += (H * H % MOD) * ((W - dx) % MOD) * dx;
        fixed2KomaCost %= MOD;
    }

    rep(dy, H)
    {
        fixed2KomaCost += (W * W % MOD) * ((H - dy) % MOD) * dy;
        fixed2KomaCost %= MOD;
    }

    ll ans = (fixed2KomaCost * comb(H * W - 2, K - 2) % MOD);
    ans = (ans % MOD + MOD) % MOD;

    cout << ans << endl;

    return 0;
}