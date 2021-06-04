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

#define LEF 0
#define RIG 1
#define UND -1

vi val; // その葉で勝つ可能性のある組数
vi result; // その葉で左右どっちのチームが勝つか 0: left, 1: right, -1: undefined
int segSize;
int K;
string S;
int Q;

int char2Result(char c){
    if(c == '?'){
        return UND;
    }
    if(c == '0'){
        return RIG;
    }
    if(c == '1'){
        return LEF;
    }
}

int recalcNode(int node){
    // cout << "recalced " << node << "\n";
    int res = result[node];
    int lch = node * 2 + 1;
    int rch = node * 2 + 2;
    if(lch >= segSize){
        if(res == LEF){
            return val[node] = 1;
        }
        if(res == RIG){
            return val[node] = 1;
        }
        if(res == UND){
            return val[node] = 2;
        }
    } else {
        if(res == LEF){
            return val[node] = val[lch];
        }
        if(res == RIG){
            return val[node] = val[rch];
        }
        if(res == UND){
            return val[node] = val[lch] + val[rch];
        }
    }
}

int updateSeg(int node, int x){ // result[node]をxに変えるとどうなるか
    result[node] = x;
    while(node > 0){
        recalcNode(node);
        node = (node - 1) / 2;
    }
    return recalcNode(0);
}

void initSeg(){
    segSize = (1 << K) - 1;
    val = vi(segSize, 1);
    result = vi(segSize, LEF);

    rep(si, segSize){
        int ri = segSize - 1 - si;
        int res = char2Result(S[si]);
        updateSeg(ri, res);
    }
}

void solve()
{
    cin >> K >> S >> Q;

    initSeg();

    rep(i, Q){
        int ri;
        char c;
        cin >> ri >> c;
        ri--;
        ri = segSize - 1 - ri;

        int x = char2Result(c);

        cout << updateSeg(ri, x) << "\n";

        rep(j, segSize){
            // show(j);
            // show(val[j]);
            // show(result[j]);
        }
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