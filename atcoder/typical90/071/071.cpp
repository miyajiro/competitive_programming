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

int N, M, K;
vi A, B, D;
vvi toArray;
vvi ansList;
vi now;

int cnt = 0;

vi usableNodes; // 現状入次数0の集合

bool dfs(int i){ // i番目を埋める
    if(cnt == K){
        return false;
    }

    if(i == N){
        ansList.eb(now);
        cnt++;
        return true;
    }

    if(usableNodes.empty()){
        return false;
    }

    rrep(xi, sz(usableNodes)){
        if(cnt == K){
            return false;
        }

        int x = usableNodes[xi]; // i番目xi
        usableNodes.erase(usableNodes.begin() + xi);
        now[i] = x;

        for(auto toNode : toArray[x]){
            D[toNode]--;
            if(D[toNode] == 0){
                usableNodes.eb(toNode);
            }
        }

        bool res = dfs(i + 1);

        for(auto toNode : toArray[x]){
            D[toNode]++;
            if(D[toNode] == 1){
                usableNodes.pop_back();
            }
        }

        usableNodes.insert(usableNodes.begin() + xi, x);
        now[i] = -1;

        if(!res){
            return false;
        }
    }

    return true;
}

void solve()
{
    cin >> N >> M >> K;
    toArray = vvi(N);
    D = vi(N, 0);
    now = vi(N, -1);

    rep(i, M){
        int a, b;
        cin >> a >> b;
        A.eb(--a);
        B.eb(--b);
        toArray[a].eb(b);
        D[b]++;
    }

    rep(i, N){
        if(D[i] == 0){
            usableNodes.eb(i);
        }
    }

    dfs(0);

    if(cnt < K){
        cout << -1 << "\n";
    } else {
        rep(k, K){
            rep(n, N){
                cout << ansList[k][n] + 1 << (n == N - 1 ? "\n" : " ");
            }
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