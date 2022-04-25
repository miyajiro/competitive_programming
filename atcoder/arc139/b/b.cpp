#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/modint>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
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
#define show(x) cerr << #x << " = " << x << "\n";
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline cout << "\n"
#define newlineErr cerr << "\n"

using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vp = vector<P>;
using vlp = vector<LP>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using mint = modint1000000007;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

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

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll  d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

ll gcd(ll x, ll y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}

ll lca(ll x, ll y){
    ll z = gcd(x, y);
    return x * y / z;
}

ll M = 30000;

void _solve(){
    ll N, A, B, X, Y, Z;
    cin >> N >> A >> B >> X >> Y >> Z;

    bool notA = (X * A <= Y);
    bool notB = (X * B <= Z);

    if(notA && notB){
        cout << N * X << "\n";
        return;
    }

    if(notA){
        swap(notA, notB);
        swap(A, B);
        swap(Y, Z);
    }

    if(notB){ // Bを使わない。Aを極力使い、あまりでX
        cout << (N / A) * Y + (N % A) * X << "\n";
        return;
    }

    // AとBを合わせて使う。
    ll minCost = 0xfffffffffffffff;
    // A目一杯
    {
        ll cost = 0;
        ll remaining = N;

        ll s = remaining / A;
        cost += s * Y;
        remaining -= s * A;

        ll t = remaining / B;
        cost += t * Z;
        remaining -= t * B;

        cost += remaining * X;

        chmin(minCost, cost);
    }

    // B目一杯
    {
        ll cost = 0;
        ll remaining = N;

        ll t = remaining / B;
        cost += t * Z;
        remaining -= t * B;

        ll s = remaining / A;
        cost += s * Y;
        remaining -= s * A;

        cost += remaining * X;

        chmin(minCost, cost);
    }

    if(A > B){
        swap(A, B);
        swap(Y, Z);
    }

    if(B >= M){
        // Bの数総当たり
        rep(t, N / B + 1){
            ll cost = 0;
            ll remaining = N;
            remaining -= t * B;
            cost += t * Z;

            ll s = remaining / A;
            remaining -= s * A;
            cost += s * Y;

            cost += remaining * X;

            chmin(minCost, cost);
        }
        goto en;
    }

    // 都合が良い方をAにする。
    if(A * Z < B * Y){
        swap(A, B);
        swap(Y, Z);
    }

    rep(u, max(A, B) + 1){ // X総当たり
        ll a = A;
        ll b = B;
        ll cost = u * X;
        ll remaining = N - u;

        ll g = gcd(a, b); // gの倍数なら実現可能

        if(remaining % g != 0){
            continue;
        }

        a /= g;
        b /= g;
        remaining /= g;

        // A, Bの組み合わせでremainingは実現可能
        ll s0, t0;
        extgcd(a, b, s0, t0);
        s0 *= remaining;
        t0 *= remaining;

        // sA + tB = N
        // s0A + t0B = N
        // s = s0 + kB
        // t = t0 - kA
        ll s = s0;
        ll t = t0;

        if(s < 0){
            ll pS = -s;
            ll k = (pS - 1) / b + 1;
            s += k * b;
            t -= k * a;
        }

        if(t < 0){
            ll pT = -t;
            ll k = (pT - 1) / a + 1;
            s -= k * b;
            t += k * a;
        }

        if(s < 0 || t < 0){
            continue;
        }

        { // B小さい
            ll k = t / a;
            s += k * b;
            t -= k * a;

            cost += s * Y + t * Z;
            chmin(minCost, cost);
        }
    }

    en: ;
    cout << minCost << "\n";
}

void solve()
{
    int t;
    cin >> t;
    rep(_, t){
        _solve();
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