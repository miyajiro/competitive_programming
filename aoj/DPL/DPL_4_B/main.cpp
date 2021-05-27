#include <bits/stdc++.h>
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
using namespace std;
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

ll N, K, L, R;
vl A;
vl dp1[21];
vl dp2[21];

void solve()
{
    cin >> N >> K >> L >> R;
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
    }

    ll N1 = N / 2;
    ll N2 = N - N1;

    rep(s, 1 << N1){
        ll sum = 0;
        ll k = 0;
        rep(ni1, N1){
            if(((s >> ni1) & 1) == 1){
                sum += A[ni1];
                k++;
            }
        }
        dp1[k].pb(sum);
    }

    rep(s, 1 << N2){
        ll sum = 0;
        ll k = 0;
        rep(ni2, N2){
            if(((s >> ni2) & 1) == 1){
                sum += A[N1 + ni2];
                k++;
            }
        }
        dp2[k].pb(sum);
    }

    rep(ni1, N1 + 1){
        sort(rng(dp1[ni1]));
    }

    rep(ni2, N2 + 1){
        sort(rng(dp2[ni2]));
    }

    ll ans = 0;
    rep(k, min(K + 1, N1 + 1)){
        // dp1[k]とdp2[K - k]
        if(K - k > N2){
            continue;
        }

        rep(i, dp1[k].size()){
            ll dp1Val = dp1[k][i];

            if(dp1Val > R){
                continue;
            }

            ll ri = upper_bound(rng(dp2[K - k]), R - dp1Val) - dp2[K - k].begin();
            ll li = lower_bound(rng(dp2[K - k]), L - dp1Val) - dp2[K - k].begin();

            ans += ri - li;
        }
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}