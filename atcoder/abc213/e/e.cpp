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

const int INF = 0xfffffff;

int H, W;
vector<string> S;
vector<vector<bool>> isWall;
vvi dist;
vi D;
// コスト1で2マスなら進める。隣が壁じゃないならコスト0で進める
int ey[4] = {-1, 0, 1, 0};
int ex[4] = {0, 1, 0, -1};

vi ey1;
vi ex1;

bool isValid(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}

int yx2N(int y, int x){
    assert(isValid(y, x));
    return y * W + x;
}

P n2YX(int n){
    return P(n / W, n % W);
}

struct E{
    int to;
    int cost;
};
vector<vector<E>> G;


void solve()
{
    cin >> H >> W;
    int N = H * W;
    S = vector<string>(H);
    isWall = vector<vector<bool>>(H, vector<bool>(W, false));
    G = vector<vector<E>>(N);

    srep(h, -2, 3){
        srep(w, -2, 3){
            if(abs(h) == 2 && abs(w) == 2){
                continue;
            }
            if(h == 0 && w == 0){
                continue;
            }
            ey1.eb(h);
            ex1.eb(w);
        }
    }

    rep(h, H){
        cin >> S[h];
        rep(w, W){
            isWall[h][w] = (S[h][w] == '#');
        }
    }

    rep(h, H){
        rep(w, W){
            rep(i, 4){
                int ny = h + ey[i];
                int nx = w + ex[i];
                if(!isValid(ny, nx)){
                    continue;
                }
                if(isWall[ny][nx]){
                    continue;
                }
                int nowN = yx2N(h, w);
                int toN = yx2N(ny, nx);

                G[nowN].eb(E{toN, 0});
            }

            rep(i, 20){
                int ny = h + ey1[i];
                int nx = w + ex1[i];
                if(!isValid(ny, nx)){
                    continue;
                }
                int nowN = yx2N(h, w);
                int toN = yx2N(ny, nx);

                G[nowN].eb(E{toN, 1});
            }
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;

    vi dp = vi(N, INF);

    dp[0] = 0;
    pq.push(P(0, 0));

    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        int now = p.sc;

        if(p.fr > dp[now]){
            continue;
        }

        for(auto e : G[now]){
            if(chmin(dp[e.to], dp[now] + e.cost)){
                pq.push(P(dp[e.to], e.to));
            }
        }
    }

    cout << dp[yx2N(H - 1, W - 1)] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}