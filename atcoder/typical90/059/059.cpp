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

int N, M, Q;
vi X, Y, A, B;
vector<ull> dp;
vvi toArray;
vector<bool> ans;

void solve()
{
    cin >> N >> M >> Q;
    toArray = vvi(N);
    rep(i, M){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        X.eb(x);
        Y.eb(y);
        toArray[x].pb(y);
    }

    rep(i, Q){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A.pb(a);
        B.pb(b);
    }

    int origQ = Q;
    Q += (64 - Q % 64) % 64;
    rep(_, Q - origQ){
        A.pb(0);
        B.pb(1);
    }

    // ここでQは64の倍数
    for(int baseQ = 0; baseQ < Q; baseQ += 64){ // Q / 64
        // [baseQ, baseQ + 64)を処理
        dp = vector<ull>(N, 0ULL);
        rep(i, 64){
            int q = baseQ + i;
            dp[A[q]] |= (1ULL << i);
        }

        rep(n, N){
            int from = n;
            for(auto to : toArray[from]){
                dp[to] |= dp[from];
            }
        }

        rep(i, 64){
            int q = baseQ + i;
            ans.eb((dp[B[q]] >> i) % 2ULL == 1ULL);
        }
    }

    rep(q, origQ){
        if(ans[q]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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