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

int AO = 0;
int TAKA = 1;

int H, W;
int A[2000][2000];
int dp[2000][2000]; // dp[h][w]このマスで盤面が渡ってきたとき、ゲーム終了までの(自分の点 - 相手の点)の最大値

void solve()
{
    cin >> H >> W;
    rep(h, H){
        string s;
        cin >> s;
        rep(w, W){
            if(s[w] == '+'){
                A[h][w] = 1;
            } else {
                A[h][w] = -1;
            }
        }
    }

    rrep(h, H){
        rrep(w, W){
            if(h == H - 1 && w == W - 1){
                dp[h][w] = 0;
                continue;
            }

            if(h == H - 1){
                dp[h][w] = A[h][w+1] - dp[h][w + 1];
                continue;
            }

            if(w == W - 1){
                dp[h][w] = A[h+1][w] - dp[h+1][w];
                continue;
            }

            dp[h][w] = max(A[h][w+1] - dp[h][w + 1], A[h+1][w] - dp[h+1][w]);
        }
    }

    if(dp[0][0] == 0){
        puts("Draw");
    } else if(dp[0][0] > 0){
        puts("Takahashi");
    } else {
        puts("Aoki");
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