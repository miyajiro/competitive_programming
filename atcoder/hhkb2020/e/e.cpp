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
bool isWall[2000][2000];
int yoko[2000][2000];
int tate[2000][2000];
int cnt[2000][2000];

using MOD = modint1000000007;
MOD pow2[4000001];

int main()
{
    cin >> H >> W;
    rep(i, H){
        string s;
        cin >> s;
        rep(j, W){
            isWall[i][j] = (s[j] == '#');
        }
    }

    pow2[0] = 1;
    rep1(i, H * W){
        pow2[i] = pow2[i - 1] * 2;
    }

    rep(h, H){
        int cnt = 0;
        rep(w, W){
            if(isWall[h][w]){
                cnt = 0;
            } else {
                cnt++;
                yoko[h][w] = cnt;
            }
        }
    }

    rep(h, H){
        rrep(w, W - 1){
            if(isWall[h][w]){
                continue;
            }

            chmax(yoko[h][w], yoko[h][w+1]);
        }
    }


    rep(w, W){
        int cnt = 0;
        rep(h, H){
            if(isWall[h][w]){
                cnt = 0;
            } else {
                cnt++;
                tate[h][w] = cnt;
            }
        }
    }

    rep(w, W){
        rrep(h, H - 1){
            if(isWall[h][w]){
                continue;
            }

            chmax(tate[h][w], tate[h+1][w]);
        }
    }

    int N = 0;

    rep(h, H){
        rep(w, W){
            cnt[h][w] = tate[h][w] + yoko[h][w] - 1;
            if(cnt[h][w] == -1){
                cnt[h][w] = 0;
            }
            if(!isWall[h][w]){
                N++;
            }
        }
    }

    MOD ans = 0;

    // rep(h, H){
    //     rep(w, W){
    //         cerr << cnt[h][w];
    //     }
    //     cerr << endl;
    // }

    rep(h, H){
        rep(w, W){
            ans += pow2[N] - pow2[N - cnt[h][w]]; // TODO
        }
    }

    cout << ans.val() << endl;

    return 0;
}