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

int N;

vector<string> compress(vector<string> S){
    int H = sz(S);
    int W = sz(S[0]);

    int minY = H;
    int maxY = -1;
    int minX = W;
    int maxX = -1;

    rep(h, H){
        rep(w, W){
            if(S[h][w] == '#'){
                chmin(minY, h);
                chmax(maxY, h);
                chmin(minX, w);
                chmax(maxX, w);
            }
        }
    }

    int newH = maxY - minY + 1;
    int newW = maxX - minX + 1;

    vector<string> res(newH);

    rep(h, newH){
        rep(w, newW){
            if(S[minY + h][minX + w] == '#'){
                res[h] += '#';
            } else {
                res[h] += '.';
            }
        }
    }

    return res;
}

vector<string> rotate(vector<string> S){
    int H = sz(S);
    int W = sz(S[0]);

    vector<string> res(W);
    rep(h, W){
        rep(w, H){
            res[h] += S[H - 1 - w][h];
        }
    }

    return res;
}

bool same(vector<string> S, vector<string> T){
    if(sz(S) != sz(T) || sz(S[0]) != sz(T[0])){
        return false;
    }

    int H = sz(S);
    int W = sz(S[0]);

    rep(h, H){
        rep(w, W){
            if(S[h][w] != T[h][w]){
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    vector<string> S2, S3, S4;

    rep(h, N){
        cin >> S[h];
    }

    rep(h, N){
        cin >> T[h];
    }

    S = compress(S);

    T = compress(T);

    S2 = rotate(S);

    S3 = rotate(S2);

    S4 = rotate(S3);

    if(same(S, T) || same(S2, T) || same(S3, T) || same(S4, T)){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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