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
vl A;

void solve()
{
    cin >> N >> K;

    rep(i, N){
        ll a;
        cin >> a;
        A.eb(a);
    }

    sort(rrng(A));

    ll ans = 0;
    ll maxJoy = A[0];
    ll maxCnt = 1;
    int now = 1;

    while(true){
        if(maxJoy == 0LL){
            break;
        }

        if(K <= maxCnt){ // maxアトラクションの数がK個以下の場合
            // show(K);
            // show(maxJoy);
            ans += K * maxJoy;
            K = 0;
            break;
        }

        ll loopNum = min(K / maxCnt, maxJoy); // maxCntで何周できるか

        if(now == N || maxJoy - loopNum > A[now]){ // 目一杯回してもA[now]にはならないとき。
            ll base = (maxJoy * (maxJoy + 1) / 2LL) - ((maxJoy - loopNum) * (maxJoy - loopNum + 1) / 2LL);
            K -= maxCnt * loopNum;
            // show(loopNum);
            // show(maxJoy);
            // show(maxCnt);
            ans += base * maxCnt;
            maxJoy -= loopNum;
            continue;
        }

        // nowを進める場合
        loopNum = min(maxJoy - A[now++], maxJoy);

        // show(loopNum);
        // show(maxJoy);
        // show(maxCnt);

        ll base = (maxJoy * (maxJoy + 1) / 2LL) - ((maxJoy - loopNum) * (maxJoy - loopNum + 1) / 2LL);
        K -= maxCnt * loopNum;
        ans += base * maxCnt;
        maxJoy -= loopNum;

        maxCnt++;
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