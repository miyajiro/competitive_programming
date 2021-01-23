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

ll N, M, Q;
vl X(200001), Y(200001);
vlp OP(200001);
vl A(200001), B(200001);

// xRev, yRev: 元座標系でのx, yの反転性
// xdiff, ydiff: 元座標系でのx, yのdiff
// rot 0, 1, 2, 3 時計回りに90*n度回転させられているか。

v(bool) xRev(200001, false), yRev(200001, false);
vl rot(200001, 0LL), xDiff(200001, 0LL), yDiff(200001, 0LL);

int main()
{
    cin >> N;
    rep1(i, N)
    {
        cin >> X[i] >> Y[i];
    }

    cin >> M;
    rep1(i, M)
    {
        cin >> OP[i].fr;
        if (OP[i].fr >= 3LL)
        {
            cin >> OP[i].sc;
        }
    }

    cin >> Q;
    rep1(i, Q)
    {
        cin >> A[i] >> B[i];
    }

    rep1(i, M)
    {
        if (OP[i].fr == 2LL)
        {
            rot[i] = (rot[i - 1] + 1LL) % 4LL;
            xRev[i] = xRev[i - 1];
            yRev[i] = yRev[i - 1];
            xDiff[i] = xDiff[i - 1];
            yDiff[i] = yDiff[i - 1];
        }
        else if (OP[i].fr == 1LL)
        {
            rot[i] = (rot[i - 1] + 3LL) % 4LL;
            xRev[i] = xRev[i - 1];
            yRev[i] = yRev[i - 1];
            xDiff[i] = xDiff[i - 1];
            yDiff[i] = yDiff[i - 1];
        }
        else
        {
            rot[i] = rot[i - 1];

            LP newOP = LP(0LL, 0LL);

            if (rot[i] == 0LL)
            {
                newOP = OP[i];
            }
            else if (rot[i] == 1LL)
            {
                if (OP[i].fr == 3LL)
                {
                    newOP.fr = 4LL;
                    newOP.sc = -OP[i].sc;
                }
                else
                {
                    newOP.fr = 3LL;
                    newOP.sc = OP[i].sc;
                }
            }
            else if (rot[i] == 2LL)
            {
                if (OP[i].fr == 3LL)
                {
                    newOP.fr = 3LL;
                    newOP.sc = -OP[i].sc;
                }
                else
                {
                    newOP.fr = 4LL;
                    newOP.sc = -OP[i].sc;
                }
            }
            else
            {
                if (OP[i].fr == 3LL)
                {
                    newOP.fr = 4LL;
                    newOP.sc = OP[i].sc;
                }
                else
                {
                    newOP.fr = 3LL;
                    newOP.sc = -OP[i].sc;
                }
            }

            if (newOP.fr == 3LL)
            {
                xRev[i] = !xRev[i - 1];
                yRev[i] = yRev[i - 1];
                xDiff[i] = ((2LL * newOP.sc) - xDiff[i - 1]);
                yDiff[i] = yDiff[i - 1];
            }
            else
            {
                xRev[i] = xRev[i - 1];
                yRev[i] = !yRev[i - 1];
                xDiff[i] = xDiff[i - 1];
                yDiff[i] = 2LL * newOP.sc - yDiff[i - 1];
            }
        }
    }

    rep1(i, Q)
    {
        ll a = A[i];
        ll b = B[i];

        ll origX = X[b];
        ll origY = Y[b];

        ll unRotatedX = xDiff[a] + (xRev[a] ? -origX : origX);
        ll unRotatedY = yDiff[a] + (yRev[a] ? -origY : origY);

        ll rotatedX = unRotatedX;
        ll rotatedY = unRotatedY;

        rep(_, rot[a])
        {
            swap(rotatedX, rotatedY);
            rotatedX = -rotatedX;
        }

        cout << rotatedX << " " << rotatedY << endl;
    }

    return 0;
}