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

vi code2Raw;
unordered_map<int, int> raw2Code;

int H;
int W;
string C[24];

bool is1(int N, int i){
    return (N >> i) % 2 == 1;
}

const int MOD = 1e9 + 7;
int dp[2][1 << 20];
int addedCodes[2][1 << 20];
int addedCodesSz[2];
bool isAdded[2][1 << 20];

int now = 0;
int nex = 1;
bool blocked[24][24];

void solve()
{
    cin >> H >> W;
    rep(h, H){
        cin >> C[h];
        rep(w, W){
            if(C[h][w] == '#'){
                blocked[h][w] = true;
            }
        }
    }

    addedCodesSz[now] = 0;
    addedCodesSz[nex] = 0;

    raw2Code[0] = 0;
    code2Raw.pb(0);

    raw2Code[1] = 1;
    code2Raw.pb(1);

    dp[nex][0] = 1;
    addedCodes[nex][addedCodesSz[nex]] = 0;
    addedCodesSz[nex]++;

    if(!blocked[0][0]){
        dp[nex][1] = 1;
        addedCodes[nex][addedCodesSz[nex]] = 1;
        addedCodesSz[nex]++;
    }

    swap(now, nex);
    rep(h, H){
        rep(w, W){
            if(h == H - 1 && w == W - 1){
                continue;
            }
            int nh, nw;
            if(w == W - 1){
                nh = h + 1;
                nw = 0;
            } else {
                nh = h;
                nw = w + 1;
            }

            rep(addedCodeI, addedCodesSz[now]){
                int code = addedCodes[now][addedCodeI];

                if(dp[now][code] == 0){
                    continue;
                }
                int raw, nextRaw0, nextRaw1, nextCode0, nextCode1;

                raw = code2Raw[code];
                nextRaw0 = raw << 1;
                if((nextRaw0 >> (W + 1)) % 2 == 1){
                    nextRaw0 ^= (1 << (W + 1));
                }
                nextRaw1 = nextRaw0 + 1;

                // 新しいのが0の場合
                auto ite0 = raw2Code.find(nextRaw0);
                if(ite0 == raw2Code.end()){
                    nextCode0 = sz(code2Raw);
                    raw2Code[nextRaw0] = nextCode0;
                    code2Raw.pb(nextRaw0);
                } else {
                    nextCode0 = ite0->sc;
                }

                dp[nex][nextCode0] += dp[now][code];
                dp[nex][nextCode0] %= MOD;
                if(!isAdded[nex][nextCode0]){
                    isAdded[nex][nextCode0] = true;
                    addedCodes[nex][addedCodesSz[nex]] = nextCode0;
                    addedCodesSz[nex]++;
                }


                // 新しいのが1の場合(validation)
                if(nw > 0 && is1(raw, W)){ // 左上
                    continue;
                }

                if(is1(raw, W - 1)){ // 上
                    continue;
                }

                if(nw < W - 1 && is1(raw, W - 2)){ // 右上
                    continue;
                }

                if(nw > 0 && is1(raw, 0)){ // 左
                    continue;
                }

                if(blocked[nh][nw]){
                    continue;
                }

                // 新しいのが1の場合(本体)
                auto ite1 = raw2Code.find(nextRaw1);
                if(ite1 == raw2Code.end()){
                    nextCode1 = sz(code2Raw);
                    raw2Code[nextRaw1] = nextCode1;
                    code2Raw.pb(nextRaw1);
                } else {
                    nextCode1 = ite1->sc;
                }

                dp[nex][nextCode1] += dp[now][code];
                dp[nex][nextCode1] %= MOD;
                if(!isAdded[nex][nextCode1]){
                    isAdded[nex][nextCode1] = true;
                    addedCodes[nex][addedCodesSz[nex]] = nextCode1;
                    addedCodesSz[nex]++;
                }
            }

            // dp初期化
            rep(addedCodeI, addedCodesSz[now]){
                int code = addedCodes[now][addedCodeI];
                dp[now][code] = 0;
            }

            // isAdded初期化
            rep(addedCodeI, addedCodesSz[nex]){
                int code = addedCodes[nex][addedCodeI];
                isAdded[nex][code] = false;
            }

            // addedCodesSz初期化
            addedCodesSz[now] = 0;

            now = 1 - now;
            nex = 1 - nex;
        }
    }

    int ans = 0;
    rep(code, sz(code2Raw)){
        ans += dp[now][code];
        ans %= MOD;
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