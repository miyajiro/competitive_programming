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

ll K;
string T, A;

ll cnt[10];
ll tori;
ll pow10[6];
ll tCnt[10];
ll aCnt[10];
ll tP, aP;

bool tWin(ll t, ll a){
    ll newTP = (tP + t * 9LL * pow10[tCnt[t]]);
    ll newAP = (aP + a * 9LL * pow10[aCnt[a]]);
    return newTP > newAP;
}

int main()
{
    cin >> K >> T >> A;

    pow10[0] = 1LL;
    rep1(i, 5){
        pow10[i] = pow10[i - 1] * 10LL;
    }

    rep1(i, 9){
        cnt[i] = K;
    }

    rep(i, 4){
        tCnt[T[i] - '0']++;
        cnt[T[i] - '0']--;
        aCnt[A[i] - '0']++;
        cnt[A[i] - '0']--;
    }

    rep1(i, 9){
        tP += i * pow10[tCnt[i]];
        aP += i * pow10[aCnt[i]];
    }

    ll bunbo = (9LL * K - 8LL) * (9LL * K - 9LL);
    ll bunshi = 0LL;

    rep1(t, 9){
        ll hidari = cnt[t];
        if(hidari <= 0LL){
            continue;
        }
        cnt[t]--;
        rep1(a, 9){
            ll migi = cnt[a];
            if(migi <= 0LL){
                continue;
            }

            // cerr << t << " " << hidari << ", " << a << " " << migi << endl;

            if(tWin(t, a)){
                bunshi += hidari * migi;
            }
        }
        cnt[t]++;
    }

    // cerr << bunshi << "/" << bunbo << endl;

    double u = (double)bunshi;
    double d = (double)bunbo;

    cout << u / d << endl;

    return 0;
}