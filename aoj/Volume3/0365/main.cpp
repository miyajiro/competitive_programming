#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

string s;
vl A;
vl R; // 反転数(自分より小さいのに大きい)
ll N;
vector<PQ(int)> char2IPQ;
ll B = 26;
ll k;

vl ans;
string ansS;

void solve()
{
    cin >> s >> k;

    if(k == 0){
        cout << s << "\n";
        return;
    }

    N = sz(s);
    char2IPQ = vector<PQ(int)>(B);
    fenwick_tree<ll> fwt(N);

    rep(i, N){
        fwt.add(i, 1);
        int a = s[i] - 'a';
        A.pb(a);
        char2IPQ[a].push(i);
    }

    rep(ansi, N){ // ans[ansi]を決める
        rep(c, B){
            if(char2IPQ[c].empty()){
                continue;
            }
            int ai = char2IPQ[c].top();
            int swapNum = fwt.sum(0, ai); // 先頭に持ってくるための数
            if(swapNum <= k){
                char2IPQ[c].pop();
                ans.pb(c);
                fwt.add(ai, -1);
                k -= swapNum;
                break;
            }
        }
    }

    rep(ai, N){
        ansS += ans[ai] + 'a';
    }

    cout << ansS << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}