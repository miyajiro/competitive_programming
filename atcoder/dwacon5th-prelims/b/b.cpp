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
vl A, B, aSum;
vl pos[2];

int main()
{
    cin >> N >> K;
    aSum.pb(0LL);
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
        aSum.pb(aSum[i] + a);
    }

    rep(i, N){ // [i, j)
        for(int j = i + 1; j < N + 1; j++){
            pos[0].pb(aSum[j] - aSum[i]);
        }
    }

    int next = 1;
    ll ans = 0;

    rrep(i, 45){
        pos[next].clear();
        int past = 1 - next;

        int cnt = 0; // i bit目が1の個数
        for(auto x : pos[past]){
            if((x >> i) % 2LL == 1LL){
                cnt++;
            }
        }

        if(cnt >= K){ // K個以上ならこしてるやつだけ次にいれる
            ans += (1LL << i);
            for(auto x : pos[past]){
                if((x >> i) % 2LL == 1LL){
                    pos[next].pb(x);
                }
            }
        } else { // K個未満なら全部次にいれる。
            for(auto x : pos[past]){
                pos[next].pb(x);
            }
        }

        next = past;
    }

    cout << ans << endl;

    return 0;
}