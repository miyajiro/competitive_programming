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

int N;
ll distSum;
vl A, B, subTreeSize, ans;
vvi G;

int dfs(int now, int from, int d){
    distSum += d;
    int s = 1;
    for(auto nex : G[now]){
        if(nex == from){
            continue;
        }

        s += dfs(nex, now, d + 1);
    }
    subTreeSize[now] = s;
    return s;
}

void dfs2(int now, int from){
    ans[now] = distSum;
    for(auto nex : G[now]){
        if(nex == from){
            continue;
        }

        distSum -= subTreeSize[nex];
        distSum += N - subTreeSize[nex];
        dfs2(nex, now);
        distSum += subTreeSize[nex];
        distSum -= N - subTreeSize[nex];
    }
}

void solve()
{
    cin >> N;
    subTreeSize = vl(N);
    ans = vl(N);
    G = vvi(N);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        A.eb(--a);
        B.eb(--b);
        G[a].eb(b);
        G[b].eb(a);
    }

    dfs(0, -1, 0);
    dfs2(0, -1);

    for(auto a : ans) {
        cout << a << "\n";
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