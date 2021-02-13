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

vv(ll) chs;
vl subsize;

ll calcSubsize(int V){
    ll res = 1LL;
    for(auto ch : chs[V]){
        res += calcSubsize(ch);
    }
    return subsize[V] = res;
}

ll dfs(ll V){ // 先手の獲得枚数-後手の獲得枚数。
    ll res = 0LL;
    ll turn = -1LL; // 1なら先手、-1なら後手。移動で先手から後手に交代。

    res += turn; // 後手はそこにおいてあるものを取れるので。
    turn = -turn;

    vl junDiffs;
    vl revDiffs;
    for(auto ch: chs[V]){
        if(subsize[ch] % 2LL == 1LL){ // rev
            revDiffs.pb(dfs(ch));
        } else {
            junDiffs.pb(dfs(ch));
        }
    }

    sort(rng(junDiffs));
    sort(rng(revDiffs));

    int jpos = junDiffs.size() - 1;
    int rpos = revDiffs.size() - 1;

    while(jpos >= 0 && junDiffs[jpos] >= 0LL){
        res += (turn * junDiffs[jpos]);
        jpos--;
    }

    while(rpos >= 0){
        res += (turn * revDiffs[rpos]);
        rpos--;
        turn = -turn;
    }

    while(jpos >= 0){
        res += (turn * junDiffs[jpos]);
        jpos--;
    }

    // cerr << "V=" << V << ", res=" << res << endl;

    return res;
}

int main()
{
    ll N;
    cin >> N;
    rep(i, N){
        chs.pb(vl());
        subsize.pb(0LL);
    }
    vl par;
    for(int i = 1; i < N; i++){
        ll p;
        cin >> p;
        p--;
        chs[p].pb(i);
    }

    calcSubsize(0);

    ll diff = dfs(0);

    cout << (N - diff) / 2LL << endl;

    return 0;
}