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

ll N, K;
vl X, Y;
ll dp[16][1 << 15]; // dp[何グループできているか][使用済みのノード] = スコア最小値

const ll INF = INT64_MAX - 2LL;

ll nijo(ll x){
    return x * x;
}

ll getDist2(int ni1, int ni2){
    return nijo(X[ni1] - X[ni2]) + nijo(Y[ni1] - Y[ni2]);
}

ll dist2[15][15];
ll maxDistInS[1 << 15];
vi unUsedNums[1 << 15];

void solve()
{
    cin >> N >> K;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.eb(x);
        Y.eb(y);
    }

    rep(i, N){
        rep(j, N){
            dist2[i][j] = getDist2(i, j);
        }
    }

    rep(k, K + 1){
        rep(s, 1 << N){
            dp[k][s] = INF;
        }
    }

    rep(s, 1 << N){
        vi niInS = vector<int>();
        ll maxDist = 0;
        rep(ni, N){
            if(((s >> ni) & 1) == 1){
                niInS.eb(ni);
            } else {
                unUsedNums[s].pb(ni);
            }
        }
        for(int niI1 = 0; niI1 < sz(niInS); niI1++){
            for(int niI2 = niI1 + 1; niI2 < sz(niInS); niI2++){
                chmax(maxDist, dist2[niInS[niI1]][niInS[niI2]]);
            }
        }
        maxDistInS[s] = maxDist;
    }

    dp[0][0] = 0;
    rep1(k, K){
        rep(s, 1 << N){
            for(int subS = s;; subS = ((subS - 1) & s)){
                chmin(dp[k][s], max(dp[k-1][subS], maxDistInS[s - subS]));
                if(subS == 0){
                    break;
                }
            }
        }
    }

    cout << dp[K][bn(N)] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}