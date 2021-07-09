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

int H, W;
vvi G;
vvi A;
vvi s2IndexArray;

void solve()
{
    cin >> H >> W;
    G = vvi(H, vi(W, 0));
    A = vvi(1 << H, vi(W, 0));
    s2IndexArray = vvi(1 << H);

    rep(h, H){
        rep(w, W){
            cin >> G[h][w];
        }
    }

    rep(s, 1 << H){
        rep(i, H){
            if((s >> i) % 2 == 1){
                s2IndexArray[s].eb(i);
            }
        }
    }

    rep(s, 1 << H){
        if(s == 0){
            continue;
        }
        rep(w, W){
            // show(s);
            // show(w);
            // show(A[s][w]);
            int val = G[s2IndexArray[s][0]][w];
            bool isSame = true;
            for(auto h : s2IndexArray[s]){
                isSame &= (val == G[h][w]);
            }

            if(isSame){
                A[s][w] = val;
            }
        }
    }

    int ans = 0;
    map<int, int> mp;
    rep(s, 1 << H){
        if(s == 0){
            continue;
        }
        int height = sz(s2IndexArray[s]);
        mp.clear();
        rep(w, W){
            int a = A[s][w];
            if(a == 0){
                continue;
            }

            if(mp.find(a) == mp.end()){
                mp[a] = 1;
            } else {
                mp[a]++;
            }
            chmax(ans, mp[a] * height);
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}