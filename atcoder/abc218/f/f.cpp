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

int inf = INT32_MAX;
int hasEdge[400][400];
int N, M;
vi S, T;
bool used[400 * 400];
int minD = 0;

vi calc(bool s){
    vvi G(N);
    vvi revG(N);
    rep(i, N){
        rep(j, N){
            if(hasEdge[i][j] != -1){
                G[i].eb(j);
                revG[j].eb(i);
            }
        }
    }

    vi D(N, inf);
    D[0] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(auto nex : G[n]){
            if(chmin(D[nex], D[n] + 1)){
                q.push(nex);
            }
        }
    }

    if(s){
        if(D[N - 1] == inf){
            D[N - 1] = -1;
        }
        cout << D[N - 1] << "\n";
        return {};
    }

    vi res;
    if(D[N - 1] == inf){
        minD = -1;
        return {};
    }
    int pos = N - 1;
    while(pos != 0){
        res.eb(pos);
        for(auto prev : revG[pos]){
            if(D[prev] == D[pos] - 1){
                used[hasEdge[prev][pos]] = true;
                pos = prev;
                break;
            }
        }
    }
    res.eb(0);
    minD = D[N - 1];
    return res;
}

void solve()
{
    cin >> N >> M;

    rep(i, N){
        rep(j, N){
            hasEdge[i][j] = -1;
        }
    }

    rep(i, M){
        int s, t;
        cin >> s >> t;
        S.eb(--s);
        T.eb(--t);
        hasEdge[s][t] = i;
    }

    calc(false);
    if(minD == inf){
        minD = -1;
    }
    rep(i, M){
        if(!used[i]){
            cout << minD << "\n";
            continue;
        }
        hasEdge[S[i]][T[i]] = -1;
        calc(true);
        hasEdge[S[i]][T[i]] = i;
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