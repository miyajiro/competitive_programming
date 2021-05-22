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

ll comb[61][61];

void combInit(){
    comb[0][0] = 1;
    rep1(n, 60){
        rep(m, n + 1){
            if(m == 0 || m == n){
                comb[n][m] = 1;
                continue;
            }
            comb[n][m] = comb[n - 1][m - 1] + comb[n - 1][m];
        }
    }
}

ll cnt(ll numA, ll numB){ // 何通りあるか
    return comb[numA + numB][numA];
}

// a numA個, b numB個で辞書順K番目の文字列
string calcK(ll numA, ll numB, ll K){
    if(numA == 0LL){
        string res = "";
        rep(_, numB){
            res += "b";
        }
        return res;
    }
    if(numB == 0LL){
        string res = "";
        rep(_, numA){
            res += "a";
        }
        return res;
    }

    ll cntA = cnt(numA - 1, numB);
    if(cntA >= K){
        return "a" + calcK(numA - 1, numB, K);
    } else {
        return "b" + calcK(numA, numB - 1, K - cntA);
    }
}


ll A, B, K;

void solve()
{
    combInit();
    cin >> A >> B >> K;
    cout << calcK(A, B, K) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}