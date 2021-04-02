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

// サイクル偶数ならいける
// まず2部彩色できるかで-1判定。

int N;
bool hasEdge[200][200];
bool visited[200];
bool isBlack[200];
int dist[200][200];

bool colorDfs(int v){
    visited[v] = true;

    rep(i, N){
        if(!hasEdge[v][i]){
            continue;
        }

        if(visited[i] && (isBlack[v] == isBlack[i])){
            return false;
        }

        if(!visited[i]){
            isBlack[i] = !isBlack[v];
            if(!colorDfs(i)){
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> N;
    rep(i, N){
        string s;
        cin >> s;
        rep(j, s.size()){
            hasEdge[i][j] = (s[j] == '1');
        }
    }

    if(!colorDfs(0)){
        puts("-1");
        return 0;
    }

    rep(i, N){
        rep(j, N){
            dist[i][j] = i == j ? 0 : 300000;
            if(hasEdge[i][j]){
                dist[i][j] = 1;
            }
        }
    }

    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 2;

    rep(i, N){
        rep(j, N){
            if(dist[i][j] == 300000){
                continue;
            }

            ans = max(ans, dist[i][j] + 1);
        }
    }

    cout << ans << endl;

    return 0;
}