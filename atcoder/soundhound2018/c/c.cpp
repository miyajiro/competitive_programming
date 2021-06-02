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
#include <atcoder/maxflow>
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

int vy[4] = {1, 0, -1, 0};
int vx[4] = {0, 1, 0, -1};
int H, W;
vector<string> C;

void solve()
{
    cin >> H >> W;
    C = vector<string>(H);
    int N = H * W + 2;
    int s = H * W;
    int t = H * W + 1;

    mf_graph<ll> mfg(N);

    rep(h, H){
        cin >> C[h];
    }

    int cnt = 0;

    rep(h, H){
        rep(w, W){
            if(C[h][w] == '*'){
                continue;
            }
            cnt++;
            bool isEven = ((h + w) % 2 == 0);

            if(isEven){
                mfg.add_edge(s, h * W + w, 1);
            } else {
                mfg.add_edge(h * W + w, t, 1);
            }

            rep(i, 4){
                int ny = h + vy[i];
                int nx = w + vx[i];
                if(isin(ny, 0, H) && isin(nx, 0, W) && C[h][w] == '.'){
                    if(isEven){
                        mfg.add_edge(h * W + w, ny * W + nx, 1);
                    } else {
                        mfg.add_edge(ny * W + nx, h * W + w, 1);
                    }
                }
            }
        }
    }

    cout << cnt - mfg.flow(s, t) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}