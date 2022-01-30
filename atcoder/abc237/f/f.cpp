#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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

using mint = modint998244353;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
using vvvvm = vector<vvvm>;

int N;
int M;



void solve()
{
    cin >> N >> M;

    vvvm dp2(N + 1, vvm(M + 3, vm(M + 3, 0))); // LIS2以下
    vvvvm dp3(N + 1, vvvm(M + 3, vvm(M + 3, vm(M + 3, 0)))); // LIS3以下

    dp2[0][M][M + 1] = 1;
    dp3[0][M][M + 1][M + 2] = 1;

    rep(i, N){
        rep(a, M + 3){
            srep(b, a + 1, M + 3){
                // dp2
                rep(nex, M){
                    int newA = a;
                    int newB = b;
                    if(nex <= a){
                        newA = nex;
                    } else if(a < nex && nex <= b){
                        newB = nex;
                    } else {
                        continue;
                    }

                    dp2[i + 1][newA][newB] += dp2[i][a][b];
                }

                // dp3
                srep(c, b + 1, M + 3){
                    rep(nex, M){
                        if(c < nex){
                            continue;
                        }

                        int newA = a;
                        int newB = b;
                        int newC = c;
                        if(nex <= a){
                            newA = nex;
                        } else if(a < nex && nex <= b){
                            newB = nex;
                        } else if(b < nex && nex <= c){
                            newC = nex;
                        } else {
                            continue;
                        }

                        dp3[i + 1][newA][newB][newC] += dp3[i][a][b][c];
                    }
                }
            }
        }
    }

    mint ika2 = 0;
    rep(a, M + 1){
        srep(b, a + 1, M + 2){
            ika2 += dp2[N][a][b];
        }
    }
    mint ika3 = 0;
    rep(a, M + 1){
        srep(b, a + 1, M + 2){
            srep(c, b + 1, M + 3){
                ika3 += dp3[N][a][b][c];
            }
        }
    }

    mint zentai = ((mint)M).pow(N); // MのN乗
    mint ijo3 = zentai - ika2;
    mint ijo4 = zentai - ika3;

    mint ans = ijo3 - ijo4;
    cout << ans.val() << '\n';
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}