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

int H, W;
int sh, sw, gh, gw;
string S[1000];
bool isWall[1000][1000];
int node[1000][1000];
int yoko[1000][1000];
int tate[1000][1000];
int nodeNum = 0;

int d[3000000];
vector<P> edges[3000000]; // to, cost

void solve()
{
    cin >> H >> W >> sh >> sw >> gh >> gw;
    sh--;
    sw--;
    gh--;
    gw--;

    rep(h, H){
        cin >> S[h];
        rep(w, W){
            isWall[h][w] = (S[h][w] == '#');
            if(!isWall[h][w]){
                node[h][w] = nodeNum++;
            }
        }
    }

    rep(h, H){
        rep(w, W){
            if(isWall[h][w]){
                continue;
            }

            if(w == W - 1 || isWall[h][w + 1]){
                yoko[h][w] = nodeNum++;
            } else {
                yoko[h][w] = nodeNum;
            }
        }
    }

    rep(w, W){
        rep(h, H){
            if(isWall[h][w]){
                continue;
            }

            if(h == H - 1 || isWall[h + 1][w]){
                tate[h][w] = nodeNum++;
            } else {
                tate[h][w] = nodeNum;
            }
        }
    }

    rep(h, H){
        rep(w, W){
            edges[node[h][w]].pb(P(tate[h][w], 1));
            edges[node[h][w]].pb(P(yoko[h][w], 1));

            edges[tate[h][w]].pb(P(node[h][w], 0));
            edges[yoko[h][w]].pb(P(node[h][w], 0));
        }
    }

    int s = node[sh][sw];
    int g = node[gh][gw];

    int inf = 0xfffffff;
    rep(i, nodeNum){
        d[i] = inf;
    }

    d[s] = 0;
    PQ(P) pq;
    pq.push(P(0, s));
    while(!pq.empty()){
        P p = pq.top();
        int now = p.sc;
        pq.pop();
        if(p.fr > d[now]){
            continue;
        }

        for(auto edge : edges[now]){
            if(chmin(d[edge.fr], d[now] + edge.sc)){
                pq.push(P(d[edge.fr], edge.fr));
            }
        }
    }

    cout << d[g] - 1 << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}