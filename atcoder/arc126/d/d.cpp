#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

int N, K;
const int INF = 0xfffffff;

int bitcnt(int s){
    int cnt = 0;
    rep(i, K){
        if((s >> i) % 2 == 1){
            cnt++;
        }
    }
    return cnt;
}

int clc(int s, int a){
    int cnt = 0;
    srep(i, a + 1, K){
        if((s >> i) % 2 == 1){
            cnt++;
        }
    }
    return cnt;
}

vvi calc(vi A){
    vvi dp(N + 1, vi(1 << K, INF));
    rep(i, N + 1){
        dp[i][0] = 0;
    }

    rep(i, N){ // dp[i][s]でdp[i+1][s | a]を埋めていく
        int a = A[i];
        rep(s, 1 << K){
            chmin(dp[i+1][s], dp[i][s] + bitcnt(s)); // 使わない
            if((s >> a) % 2 == 1){
                continue;
            }
            chmin(dp[i+1][s | (1 << a)], dp[i][s] + clc(s, a));
        }
    }
    return dp;
}

int bubble_sort(int S){
    vi A;
    rep(i, K){
        if((S >> i) % 2 == 1){
            A.eb(i);
        }
    }
    rep(i, K){
        if((S >> i) % 2 == 0){
            A.eb(i);
        }
    }
    int cnt = 0;
    rep(i, sz(A)){
        for(int j = sz(A) - 1; j > i; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j - 1]);
                cnt++;
            }
        }
    }

    return cnt;
}

void solve()
{
    cin >> N >> K;
    vi A(N), B(N);
    rep(i, N){
        cin >> A[i];
        A[i]--;
        B[N - 1 - i] = K - 1 - A[i];
    }

    vvi dp1 = calc(A);
    vvi dp2 = calc(B);

    int ans = 0xfffffff;
    vi s2REVCnt(1 << K, 0);
    rep(s, 1 << K){
        s2REVCnt[s] = bubble_sort(s);
    }

    rep(i, N + 1){
        int revI = N - i;
        rep(s, 1 << K){
            int revS = 0;
            rep(j, K){
                if((s >> j) % 2 == 0){
                    revS |= (1 << (K - 1 - j));
                }
            }

            chmin(ans, dp1[i][s] + dp2[revI][revS] + s2REVCnt[s]);
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