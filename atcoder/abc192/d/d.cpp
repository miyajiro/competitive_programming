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

string X;
ll M;
ll d;

int findMaximum(string s){
    int res = 0;
    rep(i, s.size()){
        chmax(res, s[i] - '0');
    }
    return res;
}

bool ok(ll n){ // Xをn進法で表してM以下ならtrue;
    ll base = 1LL;
    ll l = X.size();
    ll val = 0LL;

    rep(i, l){
        if(base > M){
            return false;
        }
        val += (X[l - 1 - i] - '0') * base;
        if(i < l - 1 && (((M / base) + 1LL) <= n)){
            return false;
        }
        base *= n;
    }

    if(val <= M){
        return true;
    }
    return false;
}

void solve1(string X, ll M){
    ll x = X[0] - '0';
    if(x <= M){
        puts("1");
    } else {
        puts("0");
    }
}

int main()
{
    cin >> X >> M;
    d = findMaximum(X);
    if(X.size() == 1){
        solve1(X, M);
        return 0;
    }
    ll lb = d; // true
    ll ub = M + 1; // false

    while(ub - lb > 1LL){
        ll mid = (ub + lb) / 2LL;
        if(ok(mid)){
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb - d << endl;

    return 0;
}