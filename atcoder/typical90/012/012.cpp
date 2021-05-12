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

ll H, W, Q;
int vx[4] = {1, 0, -1, 0};
int vy[4] = {0, 1, 0, -1};
bool isRed[2000][2000];

ll yx2N(ll y, ll x){
    return y * W + x;
}

bool ok(ll y, ll x){
    return isin(y, 0, H) && isin(x, 0, W);
}

int main()
{
    cin >> H >> W >> Q;

    dsu d(H * W);
    rep(_, Q){
        ll q, y, x, ya, xa, yb, xb;
        cin >> q;
        if(q == 1LL){
            cin >> y >> x;
            y--;
            x--;
            isRed[y][x] = true;
            rep(v_i, 4){
                int dy = vy[v_i];
                int dx = vx[v_i];

                int ny = y + dy;
                int nx = x + dx;
                if(!ok(ny, nx) || !isRed[ny][nx]){
                    continue;
                }

                d.merge(yx2N(y, x), yx2N(ny, nx));
            }
        } else {
            cin >> ya >> xa >> yb >> xb;
            ya--;
            xa--;
            yb--;
            xb--;
            if(isRed[ya][xa] && isRed[yb][xb] && d.same(yx2N(ya, xa), yx2N(yb, xb))){
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }

    return 0;
}