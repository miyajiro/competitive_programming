#include <bits/stdc++.h>
#include <atcoder/all>
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
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using namespace atcoder;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
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

int H, W;
v(string) grid;
// map<int, P> edgeNum2FromToPair;
int vy[] = {0, 1, 0, -1};
int vx[] = {1, 0, -1, 0};

int pair2Int(P p){
    return p.fr * W + p.sc;
}

P int2Pair(int x){
    return P( x / W, x % W);
}

bool insideGrid(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}

int main()
{
    cin >> H >> W;
    rep(i, H){
        string s;
        cin >> s;
        grid.pb(s);
    }

    int N = H * W + 2;

    mf_graph<int> mfg(N);

    rep(h, H){
        rep(w, W){
            if(grid[h][w] == '#'){
                continue;
            }
            P p = P(h, w);
            int n = pair2Int(p);

            if((h + w) % 2 == 0){
                mfg.add_edge(N - 2, n, 1);

                rep(i, 4){
                    int ny = h + vy[i];
                    int nx = w + vx[i];
                    if(!insideGrid(ny, nx) || grid[ny][nx] == '#'){
                        continue;
                    }
                    int m = pair2Int(P(ny, nx));
                    mfg.add_edge(n, m, 1);
                }
            } else {
                mfg.add_edge(n, N - 1, 1);
            }
        }
    }

    int ans = mfg.flow(N - 2, N - 1);
    for(auto edge : mfg.edges()){
        if(edge.flow == 0 || edge.from >= N - 2 || edge.to >= N - 2){
            continue;
        }
        P fp = int2Pair(edge.from);
        P tp = int2Pair(edge.to);
        int fy = fp.fr;
        int fx = fp.sc;
        int ty = tp.fr;
        int tx = tp.sc;

        if(fy == ty){
            if(fx < tx){
                grid[fy][fx] = '>';
                grid[ty][tx] = '<';
            } else {
                grid[ty][tx] = '>';
                grid[fy][fx] = '<';
            }
        } else {
            if(fy < ty){
                grid[fy][fx] = 'v';
                grid[ty][tx] = '^';
            } else {
                grid[ty][tx] = 'v';
                grid[fy][fx] = '^';
            }
        }
    }

    cout << ans << endl;
    rep(h, H){
        cout << grid[h] << endl;
    }

    return 0;
}