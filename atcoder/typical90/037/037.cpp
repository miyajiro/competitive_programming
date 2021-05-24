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

ll dp[500][10001]; // dp[ni][w] niまでの料理で香辛料w使ったときの最大値

ll W, N;
vl L, R, values;

void solve()
{
    cin >> W >> N;
    rep(i, N){
        ll l, r, val;
        cin >> l >> r >> val;
        L.pb(l);
        R.pb(r);
        values.pb(val);
    }

    for(ll w = L[0]; w <= R[0]; w++){
        dp[0][w] = values[0];
    }

    rep1(ni, N - 1){
        ll l = L[ni];
        ll r = R[ni];
        ll val = values[ni];
        priority_queue<LP> pq; // LP(dp[ni-1][w'], w')

        rep(w, W + 1){
            if(w - l >= 0 && (w - l == 0 || dp[ni - 1][w - l] > 0)){
                pq.push(LP(dp[ni - 1][w - l], w - l));
            }
            dp[ni][w] = dp[ni - 1][w];

            while(!pq.empty()){
                LP lp = pq.top();
                ll dpPast = lp.fr;
                ll w_ = lp.sc;

                if(w_ < w - r){
                    pq.pop();
                    continue;
                }

                chmax(dp[ni][w], dpPast + val);
                break;
            }
        }
    }

    cout << (dp[N - 1][W] == 0LL ? -1LL : dp[N - 1][W]) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}