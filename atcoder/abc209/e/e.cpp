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

const int WIN = 0;
const int LOSE = 1;
const int DRAW = -2;
const int UNDEF = -1;

int N, M;
vvi toArray;
vvi fromArray;

vi deg;
vi result;

vector<string> S1, S2;
vector<string> Ss;
vi A, B;

void solve()
{
    cin >> N;
    rep(i, N){
        string s;
        cin >> s;
        S1.eb(s.substr(0, 3));
        S2.eb(s.substr(s.size() - 3, 3));
        Ss.pb(S1[i]);
        Ss.pb(S2[i]);
    }
    sort(rng(Ss));
    uni(Ss);

    M = Ss.size();
    toArray = vvi(M);
    fromArray = vvi(M);
    result = vi(M, UNDEF); // その盤面が自分に回ってきたら勝てるかどうか
    deg = vi(M, 0); // そのノードの出次数


    rep(i, N){
        int a = lower_bound(rng(Ss), S1[i]) - Ss.begin();
        int b = lower_bound(rng(Ss), S2[i]) - Ss.begin();

        A.eb(a);
        B.eb(b);
        toArray[a].eb(b);
        fromArray[b].eb(a);
        deg[a]++;
    }

    queue<int> q;
    rep(m, M){
        if(deg[m] == 0){
            result[m] = LOSE;
            q.push(m);
        }
    }

    while(!q.empty()){
        int m = q.front();
        q.pop();

        for(auto from : fromArray[m]){
            if(result[from] != UNDEF){
                continue;
            }

            deg[from]--;

            if(result[m] == LOSE){
                result[from] = WIN;
                q.push(from);
            }

            if(result[m] == WIN){
                if(deg[from] == 0){
                    result[from] = LOSE;
                    q.push(from);
                }
            }
        }
    }

    rep(i, N){
        int res = result[B[i]];
        if(res == WIN){
            cout << "Aoki\n";
        } else if(res == LOSE){
            cout << "Takahashi\n";
        } else {
            cout << "Draw\n";
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