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

int K;
vi C;
ll N;
ll B;
using mint = modint1000000007;
mint dp[61][1000]; // dp[i][k]: 2^i桁で、あまりkの場合の数
int pow10_2[61]; // pow10_2[i]: 10^(2^i) % b
mint ans[61][1000];

void solve()
{
    cin >> N >> B >> K;
    rep(i, K){
        int c;
        cin >> c;
        C.pb(c);
    }

    pow10_2[0] = 10 % B;
    rep(i, 60){
        pow10_2[i+1] = (pow10_2[i] * pow10_2[i]) % B;
    }

    for(auto c : C){
        dp[0][c % B]++;
    }

    rep(i, 60){
        rep(s, B){
            rep(t, B){
                dp[i+1][(s * pow10_2[i] + t) % B] += dp[i][s] * dp[i][t];
            }
        }
    }

    // ans[i][b]: 2^i桁目まで一致させたときの値
    rep(i, B){
        ans[0][i] = 0;
    }
    if(N % 2LL == 0LL){
        ans[0][0] = 1;
    } else {
        rep(b, B){
            ans[0][b] = dp[0][b];
        }
    }

    rep1(i, 60){
        if((N >> i) % 2LL == 0LL){
            rep(b, B){
                ans[i][b] = ans[i-1][b];
            }
            continue;
        }

        rep(dpb, B){
            rep(ansb, B){
                ans[i][(dpb + ansb * pow10_2[i])%B] += dp[i][dpb] * ans[i-1][ansb];
            }
        }
    }
    cout << ans[60][0].val() << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}