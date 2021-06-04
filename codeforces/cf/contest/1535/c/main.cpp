#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder{};
using namespace atcoder;
using namespace std;

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
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
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

void _solve(){
    string s;
    cin >> s;
    vi A;
    int N = sz(s);
    rep(i, N){
        if(s[i] == '0'){
            A.pb(0);
        }
        if(s[i] == '1'){
            A.pb(1);
        }
        if(s[i] == '?'){
            A.pb(-1);
        }
    }

    int numQ = 0; // 末尾に何個?が続いてるか.
    int r = 0;
    int rVal = A[0];
    if(rVal == -1){
        numQ = 1;
    }

    ll ans = 0;

    rep(l, N){ // lが左端のときの右端となるrを求める
        if(r == l - 1){
            r = l;
            rVal = A[l];
            if(rVal == -1){
                numQ = 1;
            }
        }

        if(r - l + 1 <= numQ){ // l...r全部Qのとき
            numQ = r - l + 1;
            rVal = -1;
        }

        while(r < N - 1 && (rVal == -1 || rVal != A[r + 1])){
            r++;
            if(rVal == -1){
                if(A[r] == -1){
                    numQ++;
                } else {
                    rVal = A[r];
                    numQ = 0;
                }
            } else {
                rVal = 1 - rVal;
                if(A[r] == -1){
                    numQ++;
                } else {
                    numQ = 0;
                }
            }
        }
        ans += r - l + 1;
    }
    cout << ans << "\n";
}

void solve()
{
    int t;
    cin >> t;
    rep(_, t){
        _solve();
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}