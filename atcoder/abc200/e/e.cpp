#include <bits/stdc++.h>
#include <atcoder/all>
#define fr first
#define sc second
#define rep(i, n) for (long long i = 0LL; i < (n); ++i)
#define rep1(i, n) for (long long i = 1LL; i <= (n); ++i)
#define rrep(i, n) for (long long i = (n)-1LL; i >= 0LL; --i)
#define rrep1(i, n) for (long long i = (n); i >= 1LL; --i)
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
vl A; // A[i]: 合計iであるのは何通りか。
vl B; // B[i]: 合計i以下であるのは何通りか。
vl C;
vl D;
vl E;
vl F;

int main()
{
    cin >> N >> K;
    rep(i, 3LL * N + 1LL){
        if(i <= 2){
            A.pb(0);
            continue;
        }

        ll cnt = (i - 1LL) * (i - 2LL) / 2LL;
        if(i <= N + 2){
            A.pb(cnt);
            continue;
        }

        ll overCnt = ((i - N - 1) * (i - N - 2) / 2LL) * 3LL;
        if(i <= 2LL * N + 2LL){
            A.pb(cnt - overCnt);
            continue;
        }

        overCnt -= ((i - 2LL * N - 1) * (i - 2LL * N - 2LL) / 2LL) * 3LL;
        A.pb(cnt - overCnt);
    }

    rep(i, 3LL * N + 1LL){
        if(i == 0LL){
            B.pb(A[0]);
            continue;
        }
        B.pb(A[i] + B[i-1]);
    }

    ll sumVal = lower_bound(rng(B), K) - B.begin();
    ll order = K - B[sumVal - 1];

    // 合計sumValでの、order番目が答え。
    C.pb(0); // 綺麗さ0は0通り
    rep1(i, min(N, sumVal - 2LL)){
        if(sumVal - i > 2LL * N){
            C.pb(0);
            continue;
        }
        ll remainVal = sumVal - i;
        C.pb(min(N, remainVal - 1LL) - max(remainVal - N, 1LL) + 1LL);
    }
    rep(i, C.size()){
        if(i == 0){
            D.pb(C[0]);
            continue;
        }
        D.pb(D[i-1]+C[i]);
    }
    // D[i]: 綺麗さi以下の通り数
    ll kireisa = lower_bound(rng(D), order) - D.begin();
    order = order - D[kireisa - 1LL];

    // 合計sumVal, 綺麗さkireisaで、order番目
    ll remainVal = sumVal - kireisa;
    ll oisisa = max(1LL, remainVal - N) + order - 1LL;
    ll ninkido = sumVal - kireisa - oisisa;

    cout << kireisa << " " << oisisa << " " << ninkido << endl;

    return 0;
}