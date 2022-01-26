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

int N, K;
vvi A;
vvi tmp;

int B1[4][4] = {
    {1, 1, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
};
int B2[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 0, 1, 1},
    {0, 0, 1, 1, 1},
};
int vy[4] = {1, 0, -1, 0};
int vx[4] = {0, 1, 0, -1};

int G[6][6] = {
    {1, 1, 1, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 1, 1, 1},
};

void dfs(int y, int x){
    int n = sz(tmp);
    tmp[y][x] = 0;
    rep(i, 4){
        int ny = y + vy[i];
        int nx = x + vx[i];
        if(isin(ny, 0, n) && isin(nx, 0, n) && tmp[ny][nx] == 1){
            dfs(ny, nx);
        }
    }
}

map<int, vvi> mp; // 連結成分の増分 : 6x6のint

void check(){
    tmp = vvi(6, vi(6));
    vi f1(6);
    vi f2(6);

    rep(i, 6){
        f1[i] = f2[i] = i;
    }

    do {
        do {
            rep(i1, 6){
                rep(i2, 6){
                    tmp[i1][i2] = G[f1[i1]][f2[i2]];
                }
            }

            int cnt = 0;
            rep(y, 6){
                rep(x, 6){
                    if(tmp[y][x] == 1){
                        cnt++;
                        dfs(y, x);
                    }
                }
            }

            if(mp.find(cnt - 2) == mp.end()){
                vvi t(6, vi(6));
                rep(y, 6){
                    rep(x, 6){
                        t[y][x] = G[f1[y]][f2[x]];
                    }
                }
                mp[cnt - 2] = t;
            }
        } while(next_permutation(rng(f2)));
    } while(next_permutation(rng(f1)));
}

void solve_naive(){
    // N
    // A
    vi f1(N);
    vi f2(N);
    tmp = vvi(N, vi(N));

    rep(i, N){
        f1[i] = f2[i] = i;
    }

    do {
        do {
            rep(i1, N){
                rep(i2, N){
                    tmp[i1][i2] = A[f1[i1]][f2[i2]];
                }
            }

            int cnt = 0;
            rep(y, N){
                rep(x, N){
                    if(tmp[y][x] == 1){
                        cnt++;
                        dfs(y, x);
                    }
                }
            }

            if(cnt == N){
                rep(y, N){
                    rep(x, N){
                        cout << (A[f1[y]][f2[x]] == 1 ? "#" : ".");
                    }
                    cout << "\n";
                }
                return;
            }
        } while(next_permutation(rng(f2)));
    } while(next_permutation(rng(f1)));
}

void solve()
{
    check();

    cin >> N;
    A = vvi(N, vi(N));
    K = N / 3;
    int cnt = K;
    for(int i = 0; i + 2 < N; i += 3){
        rep(dy, 3){
            rep(dx, 3){
                A[i + dy][i + dx] = 1;
            }
        }
    }

    if(N % 3 == 1){
        int t = N - 4;
        rep(dy, 4){
            rep(dx, 4){
                A[t + dy][t + dx] = B1[dy][dx];
            }
        }
        cnt++;
    }
    if(N % 3 == 2){
        int t = N - 5;
        rep(dy, 5){
            rep(dx, 5){
                A[t + dy][t + dx] = B2[dy][dx];
            }
        }
        cnt += 2;
    }

    if(N <= 8){
        solve_naive();
        return;
    }

    {
        int pos = 0;
        while(true){
            if(cnt == N){
                break;
            }

            int diff = N - cnt; // あといくつ必要か

            auto ite = mp.upper_bound(diff);
            --ite;

            cnt += ite -> fr;

            rep(dy, 6) {
                rep(dx, 6) {
                    A[pos + dy][pos + dx] = (ite -> sc)[dy][dx];
                }
            }

            pos += 6;
        }
    }

    vector<string> ans(N);
    rep(y, N){
        rep(x, N){
            ans[y] += (A[y][x] == 1 ? "#" : ".");
        }
        cout << ans[y] << "\n";
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