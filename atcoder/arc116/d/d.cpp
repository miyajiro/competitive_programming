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

int N;
int M;
int L = 13;
using MOD = modint998244353;
MOD ans = 0;

set<string> visited;

MOD myGamma[50001];

MOD comb(int n, int m){
    if(n < m){
        MOD x = 0;
        return x;
    }
    return myGamma[n] * ((myGamma[n - m] * myGamma[m]).inv());
}

void init(){
    myGamma[0] = 1;
    rep1(i, 50000){
        myGamma[i] = myGamma[i - 1] * i;
    }
}

MOD dp[13][5001]; // dp[i][S] 2^i桁まででxor0, 和Sの場合の数。

int main()
{
    init();
    cin >> N >> M;
    if(M % 2 == 1){
        puts("0");
        return 0;
    }

    rep(s, 5001){
        if(s % 2 == 1 || s > N){
            dp[0][s] = 0;
        } else {
            dp[0][s] = comb(N, s);
        }
    }

    rep1(i, L - 1){
        int keta = 1 << i;
        for(int s = 0; s <= 5000; s++){
            int cnt = 0;
            for(int d = 0; s + d <= 5000; d += keta * 2){
                dp[i][s + d] += dp[i - 1][s] * comb(N, cnt);
                cnt += 2;
            }
        }
    }

    cout << dp[12][M].val() << endl;

    return 0;
}