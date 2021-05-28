#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
#include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder
{
};
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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

vi nodeRank;
vi nowRank;
vector<bool> isEvenNode;
string ansStr;

int solveMain(int N, int M, vi group, vi A, vi B)
{
    if (N == 1)
    {
        return 1;
    }
    vector<P> eoR; // (even, odd)
    vector<P> eeR; // (even, odd)
    vector<bool> eeUsed; // (even, odd)

    rep(mi, M){
        bool ea = isEvenNode[A[mi]];
        bool eb = isEvenNode[B[mi]];
        if(ea && eb){
            eeR.pb(P(A[mi], B[mi]));
            eeUsed.push_back(false);
        }
        if(ea && !eb){
            eoR.pb(P(A[mi], B[mi]));
        }
        if(!ea && eb){
            eoR.pb(P(B[mi], A[mi]));
        }
        if(!ea && !eb){
            ansStr += to_string(1 + A[mi]) + " " + to_string(1 + B[mi]) + "\n";
        }
    }

    int eeM = sz(eeR);
    int eeUseCnt = 0;
    while(eeUseCnt < eeM){
        rep(eem, eeM){
            if(eeUsed[eem]){
                continue;
            }
            int a = eeR[eem].fr;
            int b = eeR[eem].sc;

            if(nowRank[a] < 0 && nowRank[b] > 0){
                nowRank[a]++;
                nowRank[b]--;
                ansStr += to_string(1 + b) + " " + to_string(1 + a) + "\n";
                eeUsed[eem] = true;
                eeUseCnt++;
                goto nexLoop;
            }
            if(nowRank[a] > 0 && nowRank[b] < 0){
                nowRank[a]--;
                nowRank[b]++;
                ansStr += to_string(1 + a) + " " + to_string(1 + b) + "\n";
                eeUsed[eem] = true;
                eeUseCnt++;
                goto nexLoop;
            }
        }

        rep(eem, eeM){
            if(eeUsed[eem]){
                continue;
            }
            int a = eeR[eem].fr;
            int b = eeR[eem].sc;

            if(nowRank[a] < 0 || nowRank[b] > 0){
                nowRank[a]++;
                nowRank[b]--;
                ansStr += to_string(1 + b) + " " + to_string(1 + a) + "\n";
                eeUsed[eem] = true;
                eeUseCnt++;
                goto nexLoop;
            }
            if(nowRank[a] > 0 || nowRank[b] < 0){
                nowRank[a]--;
                nowRank[b]++;
                ansStr += to_string(1 + a) + " " + to_string(1 + b) + "\n";
                eeUsed[eem] = true;
                eeUseCnt++;
                goto nexLoop;
            }
        }

        rep(eem, eeM){
            if(eeUsed[eem]){
                continue;
            }
            int a = eeR[eem].fr;
            int b = eeR[eem].sc;

            nowRank[a]++;
            nowRank[b]--;
            ansStr += to_string(1 + b) + " " + to_string(1 + a) + "\n";
            eeUsed[eem] = true;
            eeUseCnt++;
            goto nexLoop;
        }

        nexLoop:
            ;
    }

    rep(eoi, sz(eoR)){
        int a = eoR[eoi].fr;
        int b = eoR[eoi].sc;

        if(nowRank[a] > 0){
            nowRank[a]--;
            ansStr += to_string(1 + a) + " " + to_string(1 + b) + "\n";
        } else {
            nowRank[a]++;
            ansStr += to_string(1 + b) + " " + to_string(1 + a) + "\n";
        }
    }

    int res = 0;

    for(auto node : group){
        if(isEvenNode[node] && nowRank[node] == 0){
            res++;
        }
    }

    return res;
}

void solveFunc()
{
    int N, M;
    cin >> N >> M;
    ansStr = "";
    vi A = vi(M);
    vi B = vi(M);
    nodeRank = vi(N, 0);
    nowRank = vi(N, 0);
    isEvenNode = vector<bool>(N, false);
    dsu DSU = dsu(N);

    rep(i, M)
    {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        nodeRank[A[i]]++;
        nodeRank[B[i]]++;

        DSU.merge(A[i], B[i]);
    }

    rep(i, N){
        if(nodeRank[i] % 2 == 0){
            isEvenNode[i] = true;
        }
    }

    vvi groups = DSU.groups();
    vi node2GroupId = vi(N);
    rep(gi, sz(groups))
    {
        for (auto nodeNum : groups[gi])
        {
            node2GroupId[nodeNum] = gi;
        }
    }

    int ans = 0;
    rep(gi, sz(groups))
    {
        vi _A = vi();
        vi _B = vi();
        rep(mi, M)
        {
            if (node2GroupId[A[mi]] == gi)
            {
                _A.pb(A[mi]);
                _B.pb(B[mi]);
            }
        }

        ans += solveMain(sz(groups[gi]), sz(_A), groups[gi], _A, _B);
    }

    cout << ans << "\n";
    cout << ansStr;
}

void solve()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        solveFunc();
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