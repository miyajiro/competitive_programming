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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

using mint = modint998244353;
int N, M;
vvi mat;
vector<bool> usedRow;
vector<bool> okCol;
vi S;
vvi A;
vi Ws;
vi w2Pos;
vi oldW2NewW;
int X;

int H, W, matRank;

void add(int row1, int row2){ // row1 ^= row2
    rep(w, W){
        mat[row1][w] ^= mat[row2][w];
    }
}

vi addV(vi a, vi b){
    vi res;
    rep(i, sz(a)){
        res.pb(a[i] ^ b[i]);
    }
    return res;
}

void solve()
{
    cin >> N >> M;
    H = N;
    W = M;
    mat = vvi(H, vi(W, 0));
    usedRow = vector<bool>(H, false);
    okCol = vector<bool>(W, false);
    w2Pos = vi(W, -1);
    oldW2NewW = vi(W);
    A = vvi(N);

    rep(i, N){
        int t;
        cin >> t;
        rep(_, t){
            int a;
            cin >> a;
            A[i].pb(--a);
        }
    }

    int cntW = 0;
    rep(w, W){
        int a;
        cin >> a;
        S.pb(a);
        if(a == 1){
            oldW2NewW[w] = cntW++;
            X++;
        }
    }
    rep(w, W){
        if(S[w] == 0){
            oldW2NewW[w] = cntW++;
        }
    }

    rep(i, N){
        for(auto w : A[i]){
            mat[i][oldW2NewW[w]] = 1;
        }
    }

    rep(w, W){ // 1個だけ残して他全部
        int posH = -1;
        rep(h, H){
            if(!usedRow[h] && mat[h][w] == 1){
                posH = h;
                break;
            }
        }

        if(posH == -1){
            continue;
        }
        w2Pos[w] = posH;

        okCol[w] = true;
        matRank++;
        usedRow[posH] = true;
        rep(h, H){
            if(h == posH || mat[h][w] == 0){
                continue;
            }
            add(h, posH);
        }
    }

    int n = H - matRank;
    mint ans = 1;

    vi check = vi(W, 0);
    rep(x, X){
        int pos = w2Pos[x];
        if(pos != -1){
            check = addV(check, mat[pos]);
        }
    }

    rep(x, X){
        if(check[x] == 0){ // xが1にならない場合
            goto ans0;
        }
    }

    srep(w, X, W){ // w (X <= w)が1になっちゃう場合
        if(check[w] == 1){
            goto ans0;
        }
    }

    rep(i, n){
        ans *= 2;
    }

    cout << ans.val() << "\n";
    return;


    ans0:
    cout << 0 << "\n";
    return;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}