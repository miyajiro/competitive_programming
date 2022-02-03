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
#define show(x) cerr << #x << " = " << x << "\n";
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

int N = 9;
int M;
vvi G;
map<string, int> mp;

using T = pair<int, string>;

void solve()
{
    cin >> M;

    G = vvi(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        G[--a].eb(--b);
        G[b].eb(a);
    }

    PQ(T) pq;
    string s = "000000000";
    string g = "123456780";
    rep(i, 8){
        int a;
        cin >> a;
        s[--a] = '1' + i;
    }

    // show(s);
    // show(g);

    mp[s] = 0;
    pq.push(T{0, s});

    while(!pq.empty()){
        T t = pq.top();
        pq.pop();

        int cost = t.fr;
        string now = t.sc;

        if(mp[now] < cost){
            continue;
        }

        int zeroI = 0;
        while(now[zeroI] != '0'){
            zeroI++;
        }

        for(auto swapee : G[zeroI]){
            string nex = now;
            swap(nex[zeroI], nex[swapee]);

            auto ite = mp.find(nex);

            if(ite == mp.end() || (ite->sc > cost + 1)){
                // if(ite != mp.end()){
                //     show(4);
                // }
                mp[nex] = cost + 1;
                pq.push(T{cost + 1, nex});
            }
        }
    }

    if(mp.find(g) == mp.end()){
        cout << -1 << "\n";
    } else {
        cout << mp[g] << "\n";
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