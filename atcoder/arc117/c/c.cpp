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

using MOD = modint;

int N;
int dansu;
string c;
vi _A, A;
ll Cs[4][4];

ll C(ll n, ll r)
{
    ll p = 3;
    ll mul = 1;
	while(n>0){
		mul *= Cs[(ll)(n%p)][(ll)(r%p)];
		mul %= p;
		n /= p; r /= p;
	}
	return mul % 3;
}

int main()
{
    cin >> N;
    cin >> c;
    MOD::set_mod(3);

    MOD ans = 0;

    Cs[0][0] = 1;
    Cs[1][0] = 1;
    Cs[1][1] = 1;
    Cs[2][0] = 1;
    Cs[2][1] = 2;
    Cs[2][2] = 1;
    Cs[3][0] = 1;
    Cs[3][1] = 3;
    Cs[3][2] = 3;
    Cs[3][3] = 1;

    rep(i, N){
        if(c[i] == 'B'){
            A.pb(0);
        }
        if(c[i] == 'W'){
            A.pb(1);
        }
        if(c[i] == 'R'){
            A.pb(2);
        }
    }

    ll n = N - 1LL;
    rep(i, N){
        // nCiを計算させる
        ans += C(n, i) * A[i];
    }
    rep(i, N - 1){
        ans *= 2LL;
    }

    if(ans.val() == 0){
        puts("B");
    } else if(ans.val() == 1){
        puts("W");
    } else {
        puts("R");
    }

    return 0;
}