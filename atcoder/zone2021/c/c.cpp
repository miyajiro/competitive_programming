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

ll N;
vl A, B, C, D, E;
bool exist[32];

bool ok(ll score){
    rep(i, 32){
        exist[i] = false;
    }

    exist[0] = true;

    rep(i, N){
        int s = 0;
        if(A[i] >= score){
            s += 1;
        }
        if(B[i] >= score){
            s += 2;
        }
        if(C[i] >= score){
            s += 4;
        }
        if(D[i] >= score){
            s += 8;
        }
        if(E[i] >= score){
            s += 16;
        }
        exist[s] = true;
    }

    if(exist[31]){
        return true;
    }

    rep(i, 32){
        for(int j = i + 1; j < 32; j++){
            for(int k = j + 1; k < 32; k++){
                if(exist[i] && exist[j] && exist[k] && ((i | j | k)== 31)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    cin >> N;
    rep(i, N){
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        A.pb(a);
        B.pb(b);
        C.pb(c);
        D.pb(d);
        E.pb(e);
    }

    ll lb = 1;
    ll ub = 1000000001;
    // lb ok ub notOK

    while(ub - lb > 1LL){
        ll mid = (ub + lb) / 2LL;
        if(ok(mid)){
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb << endl;

    return 0;
}