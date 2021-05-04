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

int N;
ll D;
vl X, Y;

bool ok(ll x1, ll x2){
    if(x1 > x2){
        swap(x1, x2);
    }

    return D <= (x2 - x1);
}

int main()
{
    cin >> N >> D;

    two_sat twoSat(N);

    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }

    rep(i, N){
        for(int j = i + 1; j < N; j++){
            if(!ok(X[i], X[j])){
                twoSat.add_clause(i, false, j, false);
            }
            if(!ok(X[i], Y[j])){
                twoSat.add_clause(i, false, j, true);
            }
            if(!ok(Y[i], X[j])){
                twoSat.add_clause(i, true, j, false);
            }
            if(!ok(Y[i], Y[j])){
                twoSat.add_clause(i, true, j, true);
            }
        }
    }

    if(!twoSat.satisfiable()){
        puts("No");
        return 0;
    }
    puts("Yes");

    v(bool) twoSatAnswer = twoSat.answer();
    rep(i, N){
        cout << (twoSatAnswer[i] ? X[i] : Y[i]) << endl;
    }

    return 0;
}