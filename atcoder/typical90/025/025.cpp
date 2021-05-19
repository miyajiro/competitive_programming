#include <bits/stdc++.h>
#include <atcoder/all>
#define fr first
#define sc second
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
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

ll N, B, ans = 0;

void dfs(string str, int nowMax){
    if(sz(str) == 11){
        ll allProd = 1LL;
        for(char c : str){
            ll n = c - '0';
            if(n > 0LL){
                allProd *= n;
            }
        }
        ll m = allProd + B;
        if(m > N){
            return;
        }

        ll _m = m;
        while(_m > 0LL){
            if(_m % 10LL == 0LL){
                return;
            }
            _m /= 10LL;
        }

        string strM = "";

        rep(i, 11){
            strM += ('0' + (int)(m % 10LL));
            m /= 10LL;
        }
        sort(rng(strM));
        if(str == strM){
            ans++;
        }
        return;
    }

    for(int i = nowMax; i <= 9; i++){
        string str2 = str + (char)('0' + i);
        dfs(str2, i);
    }
}

void solve()
{
    cin >> N >> B;

    ll _B = B;
    while(_B > 0){
        if(_B % 10LL == 0 && B <= N){
            ans++;
            break;
        }
        _B /= 10LL;
    }

    dfs("", 0);
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}