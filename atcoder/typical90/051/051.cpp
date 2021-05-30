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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

int N, N1, N2;
ll K, maxPrice;
vector<vl> dp1; // dp[k]: k個選んだときの全通りの値段を格納
vl A;

void solve()
{
    cin >> N >> K >> maxPrice;
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
    }
    N1 = N / 2;
    N2 = N - N1;
    dp1 = vector<vl>(N1 + 1);

    rep(s1, 1 << N1){
        int k = pcnt(s1);
        ll priceSum = 0;
        rep(ni, N1){
            if(((s1 >> ni) & 1) == 1){
                priceSum += A[ni];
            }
        }
        dp1[k].pb(priceSum);
    }

    rep(k, N1 + 1){
        sort(rng(dp1[k]));
    }

    ll ans = 0;

    rep(s2, 1 << N2){
        int k = pcnt(s2);
        ll priceSum = 0;
        rep(ni, N2){
            if(((s2 >> ni) & 1) == 1){
                priceSum += A[N1 + ni];
            }
        }

        if(k > K || priceSum > maxPrice || k + N1 < K){
            continue;
        }

        ll maxPrice1 = maxPrice - priceSum;
        int k1 = K - k;

        ans += upper_bound(rng(dp1[k1]), maxPrice1) - dp1[k1].begin();
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