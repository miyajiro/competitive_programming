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

string S, T;
vi ax, bx, ay, by;


bool willStay(int D, int N, int S, vi A, vi B){ // コマが残るならtrue
    int l = 1, r = D; // l <= x <= rで落ちない。
    rrep(i, N){
        // B(落としたくない)を処理
        if(B[i] == 1){
            l = max(1, l - 1);
        } else if (B[i] == -1){
            r = min(D, r + 1);
        }

        // A(落としたい)を処理
        if(A[i] == 1){
            r--;
        } else if (A[i] == -1){
            l++;
        }

        if(l > r){
            return false;
        }
    }

    if(l <= S && S <= r){
        return true;
    }
    return false;
}

int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    int sy, sx;
    cin >> sy >> sx;
    cin >> S >> T;

    rep(i, N){
        if(S[i] == 'L'){
            ay.pb(0);
            ax.pb(-1);
        } else if(S[i] == 'R') {
            ay.pb(0);
            ax.pb(1);
        } else if(S[i] == 'U') {
            ay.pb(-1);
            ax.pb(0);
        } else {
            ay.pb(1);
            ax.pb(0);
        }

        if(T[i] == 'L'){
            by.pb(0);
            bx.pb(-1);
        } else if(T[i] == 'R') {
            by.pb(0);
            bx.pb(1);
        } else if(T[i] == 'U') {
            by.pb(-1);
            bx.pb(0);
        } else {
            by.pb(1);
            bx.pb(0);
        }
    }

    if(willStay(H, N, sy, ay, by) && willStay(W, N, sx, ax, bx)){
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}