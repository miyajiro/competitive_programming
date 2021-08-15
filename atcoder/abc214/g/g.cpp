#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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

using mint = modint1000000007;
int N;
vi A, B, b2I;

mint dfs(int n, int k){ // 0~nまで埋めてn以下をk個使った場合の数(見えていないものは全て同一視)
    // n - 1 k - 1
    // n - 1 k の2つから遷移

}

void solve()
{
    cin >> N;
    b2I = vi(N + 1);
    rep(i, N){
        int a;
        cin >> a;
        A.eb(a);
    }
    rep(i, N){
        int b;
        cin >> b;
        b2I[b] = i;
    }
    rep(i, N){
        A[i] = b2I[A[i]];
        show(A[i]);
    }

    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    priority_queue<int, vector<int>, greater<int>> pq;
    int underCnt = 0;
    int sameCnt = 0;
    int overCnt = 0;
    rep(n, N){
        while(!pq.empty() && pq.top() <= n - 1){
            if(pq.top() == n - 1){
                sameCnt++;
            } else {
                underCnt++;
            }
            pq.pop();

        }
        rep(k, n + 1){
            int _n = N - n;
            if(n > _n){
                continue;
            }

            if(k == 0){
                dp[n][0] = 1;
                continue;
            }

            dp[n][k] = dp[n - 1][k - 1];
            
        }
        pq.push(A[n]);
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