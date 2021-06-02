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

int N, S;
vector<vector<bool>> dp;
vi A, B;

void solve()
{
    cin >> N >> S;
    rep(i, N){
        int a, b;
        cin >> a >> b;
        A.pb(a);
        B.pb(b);
    }

    dp = vector<vector<bool>>(N + 1, vector<bool>(S + 1, false)); // dp[i][s] 0~i-1まででs円実現可能ならtrue
    dp[0][0] = true;
    rep(i, N){
        rep(s, S){
            if(!dp[i][s]){
                continue;
            }

            if(s + A[i] <= S){
                dp[i + 1][s + A[i]] = true;
            }
            if(s + B[i] <= S){
                dp[i + 1][s + B[i]] = true;
            }
        }
    }

    if(!dp[N][S]){
        puts("Impossible");
        return;
    }

    vector<string> ans(N);
    int now = S;
    rrep(i, N){
        if(now - A[i] >= 0 && dp[i][now - A[i]]){
            now = now - A[i];
            ans[i] = "A";
        } else {
            now = now - B[i];
            ans[i] = "B";
        }
    }

    for(auto s : ans){
        cout << s;
    }
    cout << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}