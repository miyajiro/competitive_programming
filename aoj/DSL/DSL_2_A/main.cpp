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

int N, Q;
int BN;
vi A;
vi bMin;
const int inf = INT32_MAX;

void solve()
{
    cin >> N >> Q;
    // int B = floor(sqrt(N));
    int B = 3300;

    BN = N / B;
    A = vi(N, inf);
    bMin = vi(BN, inf);

    rep(q, Q){
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 0){
            A[x] = y;
            int b_n = x / B;
            if(b_n < BN){
                bMin[b_n] = inf;
                srep(i, b_n * B, (b_n + 1) * B){
                    chmin(bMin[b_n], A[i]);
                }
            }
        } else {
            y++;
            int lbn = dup(x, B);
            int rbn = y / B;
            int ans = inf;
            if(lbn >= rbn){
                srep(i, x, y){
                    chmin(ans, A[i]);
                }
            } else {
                int lbi = lbn * B;
                int rbi = rbn * B;
                srep(i, x, lbi){
                    chmin(ans, A[i]);
                }
                srep(bi, lbn, rbn){
                    chmin(ans, bMin[bi]);
                }
                srep(i, rbi, y){
                    chmin(ans, A[i]);
                }
            }
            cout << ans << "\n";
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