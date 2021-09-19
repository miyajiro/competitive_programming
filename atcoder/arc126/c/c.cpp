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
#define show(x) cerr << #x << " = " << x << "\n";
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
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
using vvl = vector<vl>;
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

ll N, K;
vl A, imosA;
int B = 600;

ll calcSum(int l, int r){
    assert(0 <= l && r <= N);
    return imosA[r] - imosA[l];
}

void solve()
{
    cin >> N >> K;
    ll sumA = 0;
    ll maxA = 0;
    imosA = vl(N + 1, 0);

    rep(i, N){
        ll a;
        cin >> a;
        sumA += a;
        chmax(maxA, a);
        A.eb(a);
    }

    if(maxA * N - sumA <= K){ // 全部に同じ数分配する場合
        K -= (maxA * N - sumA);
        ll ans = maxA;
        ans += K / N;
        cout << ans << "\n";
        return;
    }

    sort(rng(A));
    rep(i, N){
        imosA[i + 1] = imosA[i] + A[i];
    }

    int ans = 1; // ここで答えがmaxA未満であると確定
    rep1(x, B - 1){ // 愚直
        ll cost = 0;
        rep(ni, N){
            ll a = A[ni];
            if(a % x == 0){
                continue;
            }
            cost += (x - a % x);
        }
        if(cost <= K){
            chmax(ans, x);
        }
    }

    srep(x, B, maxA){ // 工夫するところ
        // x >= 600
        int sizeB = (maxA - 1) / x + 1;
        ll cnt = 0;
        rep(b, sizeB){
            int minVal = b * x + 1;
            int maxVal = (b + 1) * x;
            ll goal = (b + 1) * x;

            ll l = lower_bound(rng(A), minVal) - A.begin();
            ll r = upper_bound(rng(A), maxVal) - A.begin();

            cnt += (r - l) * goal - (imosA[r] - imosA[l]);
        }
        if(cnt <= K){
            chmax(ans, x);
        }
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