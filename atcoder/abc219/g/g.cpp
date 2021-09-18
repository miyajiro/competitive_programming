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

const int B = 650;

struct T{
    int tmpColor;
    int tmpTime;
    int selfColor;
    int selfTime;
};

int N, M, Q;
vi X, Y;
vvi G, starG;
vi R;
vector<bool> isStar;
vector<T> nodes;

void solve()
{
    cin >> N >> M >> Q;
    G = vvi(N);
    starG = vvi(N);
    R = vi(N);
    isStar = vector<bool>(N, false);
    nodes = vector<T>(N, T{1, -1, 1, -1});

    rep(i, N){
        nodes[i].selfColor = i + 1;
        nodes[i].tmpColor = i + 1;
    }

    rep(i, M){
        int a, b;
        cin >> a >> b;
        G[--a].eb(--b);
        G[b].eb(a);
        R[a]++;
        R[b]++;
    }

    rep(n, N){
        if(R[n] >= B){
            isStar[n] = true;
        }
    }

    rep(n, N){
        for(auto nex : G[n]){
            if(isStar[nex]){
                starG[n].eb(nex);
            }
        }
    }

    rep(q, Q){
        int x, y;
        cin >> x;
        T& node = nodes[--x];

        // 次数B以上の周囲から情報取得
        P connectedTimeAndColorMax = P(node.tmpTime, node.tmpColor);
        for(auto star : starG[x]){
            T starNode = nodes[star];
            if(connectedTimeAndColorMax.first < starNode.selfTime){
                connectedTimeAndColorMax = P(starNode.selfTime, starNode.selfColor);
            }
        }
        y = connectedTimeAndColorMax.sc;

        node.selfColor = y;
        node.selfTime = q;
        node.tmpColor = y;
        node.tmpTime = q;

        if(isStar[x]){
            // 次数B以上の周囲を更新
            for(auto star : starG[x]){
                T& starNode = nodes[star];
                starNode.tmpColor = y;
                starNode.tmpTime = q;
            }
        } else {
            // 周囲の頂点全部更新
            for(auto g : G[x]){
                T& node = nodes[g];
                node.tmpColor = y;
                node.tmpTime = q;
            }
        }
    }

    rep(i, N){
        int x = i;
        T& node = nodes[x];

        // 次数B以上の周囲から情報取得
        P connectedTimeAndColorMax = P(node.tmpTime, node.tmpColor);
        for(auto star : starG[x]){
            T starNode = nodes[star];
            if(connectedTimeAndColorMax.first < starNode.selfTime){
                connectedTimeAndColorMax = P(starNode.selfTime, starNode.selfColor);
            }
        }
        int y = connectedTimeAndColorMax.sc;
        cout << y;
        if(i == N - 1){
            cout << "\n";
        } else {
            cout << " ";
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