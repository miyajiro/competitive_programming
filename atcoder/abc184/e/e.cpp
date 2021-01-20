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

const int INF = 1e+8;

int H, W;
int N;
v(string) a;
vi ey{0, 1, 0, -1}, ex{1, 0, -1, 0};

vi d; //

int s, g;

inline int getInt()
{
    int x;
    scanf("%d", &x);
    return x;
}
inline string getString()
{
    string x;
    cin >> x;
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

bool ok(int y, int x)
{
    return 0 <= y && y < H && 0 <= x && x < W && a[y][x] != '#';
}

int indexFromYX(int y, int x)
{
    return y * W + x;
}

deque<int> q;

struct Edge
{
    int to;
    int cost;
};

bool isAlphabet(char c)
{
    return 'a' <= c && c <= 'z';
}

int getAlphabetIndex(char c)
{
    return W * H + (c - 'a');
}

void cerrDMap()
{
    rep(h, H)
    {
        rep(w, W)
        {
            if (d[indexFromYX(h, w)] == INF)
                cerr << "$";
            else
                cerr << d[indexFromYX(h, w)];
        }
        cerr << endl;
    }

    rep(i, 26)
    {
        if (d[N + i] != INF)
            cerr << (char)('a' + i) << ": " << d[N + i] << endl;
    }
}

int main()
{
    cin >> H >> W;
    N = H * W + 26;

    vv(Edge) edgesArray(N, v(Edge)(0));

    rep(h, H)
    {
        a.pb(getString());
    }

    rep(h, H)
    {
        rep(w, W)
        {
            if (!ok(h, w))
                continue;

            int nodeId = indexFromYX(h, w);

            if (isAlphabet(a[h][w]))
            {
                int alphabetId = getAlphabetIndex(a[h][w]);
                edgesArray[nodeId].pb(Edge({alphabetId, 1}));
                edgesArray[alphabetId].pb(Edge({nodeId, 0}));
            }

            rep(ei, 4)
            {
                int toY = h + ey[ei];
                int toX = w + ex[ei];

                if (!ok(toY, toX))
                    continue;

                int to = indexFromYX(toY, toX);

                edgesArray[nodeId].pb(Edge({to, 1}));
            }

            if (a[h][w] == 'S')
            {
                s = nodeId;
            }
            else if (a[h][w] == 'G')
            {
                g = nodeId;
            }
        }
    }

    rep(i, N)
    {
        d.pb(INF);
    }

    d[s] = 0;
    q.push_back(s);

    while (!q.empty())
    {
        int from = q.front();
        q.pop_front();

        for (auto edge : edgesArray[from])
        {
            int newD = d[from] + edge.cost;
            if (newD < d[edge.to])
            {
                d[edge.to] = newD;
                if (edge.cost == 1)
                {
                    q.push_back(edge.to);
                }
                else
                {
                    q.push_front(edge.to);
                }
            }
        }
    }

    cout << ((d[g] == INF) ? -1 : d[g]) << endl;

    return 0;
}