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

int N, M;
vi K; // 各筒に何個入ってるか
vvi A; // 各筒に入ってるボール達の色
vi now; // 各筒のインデックス
vi topCnt; // 各色について、取り出せる状態にある数
vvi col2Tsu; // 各色について、入ってる筒の番号
queue<int> q; // 取り出せるボールの色

void solve()
{
    cin >> N >> M;
    A = vvi(M);
    now = vi(M, 0);
    topCnt = vi(N, 0);
    col2Tsu = vvi(N);

    rep(mi, M){
        int k;
        cin >> k;
        K.eb(k);
        rep(ki, k){
            int a;
            cin >> a;
            A[mi].eb(--a);
            col2Tsu[a].eb(mi);
        }

        int topCol = A[mi][0];
        topCnt[topCol]++;
        if(topCnt[topCol] == 2){
            q.push(topCol);
        }
    }

    int removeColNum = 0;

    while(!q.empty()){
        int removeCol = q.front();
        q.pop();

        topCnt[removeCol] = 0;
        removeColNum++;
        for(auto tsu : col2Tsu[removeCol]){
            now[tsu]++;
            if(now[tsu] == K[tsu]){
                continue;
            }
            int nextCol = A[tsu][now[tsu]];
            topCnt[nextCol]++;
            if(topCnt[nextCol] == 2){
                q.push(nextCol);
            }
        }
    }

    if(N == removeColNum){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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