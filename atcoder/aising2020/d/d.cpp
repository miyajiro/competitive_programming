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

ll popcount(ll n){
    ll res = 0;
    while(n > 0){
        if(n % 2LL == 1LL){
            res++;
        }
        n /= 2LL;
    }
    return res;
}

ll g(ll n){
    return n % popcount(n);
}

ll f(ll n){
    ll res = 0;
    while(n > 0){
        n = g(n);
        res++;
    }
    return res;
}

ll N;
string X;
ll pow2[2][200001];
ll cntArray[2];
ll fN[2];

int main()
{
    cin >> N;
    cin >> X;
    ll cnt_ = 0LL;
    rep(i, N){
        if(X[i] == '1'){
            cnt_++;
        }
    }
    cntArray[0] = cnt_ - 1LL;
    cntArray[1] = cnt_ + 1LL;

    pow2[0][0] = pow2[1][0] = 1LL;
    rep(i, 2){
        rep1(j, N){
            if(cntArray[i] <= 0){
                continue;
            }
            pow2[i][j] = (pow2[i][j-1] * 2LL) % cntArray[i];
        }
    }

    rep(i, 2){
        if(cntArray[i] <= 0){
            continue;
        }
        rep(xi, N){
            ll n = N - 1LL - xi;
            if(X[xi] == '0'){
                continue;
            }
            fN[i] = (fN[i] + pow2[i][n]) % cntArray[i];
        }
    }

    rep(xi, N){
        int d = (X[xi] == '1' ? 0 : 1);
        ll n = N - 1LL - xi;
        ll cnt = cntArray[d];
        if(cnt == 0){
            cout << 0 << endl;
            continue;
        }

        ll now = fN[d];
        if(d == 0LL){ // 1減る
            now = (((now - pow2[d][n]) % cnt) + cnt) % cnt;
        } else { // 1増える
            now = (now + pow2[d][n]) % cnt;
        }

        cout << f(now) + 1LL << endl;
    }

    return 0;
}