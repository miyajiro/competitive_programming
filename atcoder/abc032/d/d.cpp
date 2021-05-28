#include <bits/stdc++.h>
// #include <atcoder/all>
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
// using namespace atcoder;
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

ll N, W;
vl val, weight;
bool b1, b2, b3;

void solve1(){ // N <= 30
    ll N1 = N / 2LL;
    ll N2 = N - N1;

    vector<LP> wAndV1;
    vector<LP> wAndV2;

    wAndV1.pb(LP(0, 0));
    wAndV2.pb(LP(0, 0));

    rep(s1, 1 << N1){
        ll sumW = 0;
        ll sumV = 0;
        rep(ni1, N1){
            if(((s1 >> ni1) & 1) == 0){
                continue;
            }
            sumW += weight[ni1];
            sumV += val[ni1];
        }

        if(sumW > W){
            continue;
        }

        wAndV1.pb(LP(sumW, sumV));
    }

    rep(s2, 1 << N2){
        ll sumW = 0;
        ll sumV = 0;
        rep(ni2, N2){
            if(((s2 >> ni2) & 1) == 0){
                continue;
            }
            sumW += weight[N1 + ni2];
            sumV += val[N1 + ni2];
        }

        if(sumW > W){
            continue;
        }

        wAndV2.pb(LP(sumW, sumV));
    }

    sort(rng(wAndV1));
    sort(rng(wAndV2));

    rep1(i1, sz(wAndV1) - 1){
        chmax(wAndV1[i1].sc, wAndV1[i1 - 1].sc);
    }

    rep1(i2, sz(wAndV2) - 1){
        chmax(wAndV2[i2].sc, wAndV2[i2 - 1].sc);
    }

    ll ans = 0;
    rep(i1, sz(wAndV1)){
        ll w1 = wAndV1[i1].fr;
        ll v1 = wAndV1[i1].sc;

        ll maxW2 = W - w1;
        assert(maxW2 >= 0);

        int i2 = lower_bound(rng(wAndV2), LP(maxW2 + 1, 0)) - wAndV2.begin() - 1;
        ll w2 = wAndV2[i2].fr;
        ll v2 = wAndV2[i2].sc;
        // if(v1 + v2 == 3372LL){
        //     show(w1);
        //     show(v1);
        //     show(w2);
        //     show(v2);
        // }
        chmax(ans, v1 + v2);
    }

    cout << ans << "\n";
}

void solve2(){ // weight <= 1000
    ll weightSum = 0;
    rep(i, N){
        weightSum += weight[i];
    }
    chmin(W, weightSum);

    vl dp(W + 1, 0); // dp[w]: 重さw以下での価値最大

    rep(ni, N){
        rrep(w, W + 1){
            if(w - weight[ni] < 0){
                continue;
            }

            chmax(dp[w], dp[w - weight[ni]] + val[ni]);
        }
    }

    rep1(i, W){
        chmax(dp[i], dp[i - 1]);
    }

    cout << dp[W] << "\n";
}

void solve3(){ // val <= 1000
    ll valSum = 0;
    rep(i, N){
        valSum += val[i];
    }

    ll inf = 0xffffffffff;

    vl dp(valSum + 1, inf); // dp[val]: 価値valを実現するためのwの最小値　
    dp[0] = 0;

    rep(ni, N){
        rrep(v, valSum + 1){
            if(v - val[ni] < 0 || dp[v - val[ni]] == inf){
                continue;
            }

            chmin(dp[v], dp[v - val[ni]] + weight[ni]);
        }
    }

    ll ans = 0;
    rep(i, valSum + 1){
        if(dp[i] <= W){
            ans = i;
        }
    }

    cout << ans << "\n";
}

void solve()
{
    cin >> N >> W;
    b1 = (N <= 30);
    b2 = true;
    b3 = true;

    rep(i, N){
        ll v, w;
        cin >> v >> w;

        b2 &= (w <= 1000);
        b3 &= (v <= 1000);

        val.pb(v);
        weight.pb(w);
    }

    if(b1){
        solve1();
    } else if(b2){
        solve2();
    } else {
        solve3();
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