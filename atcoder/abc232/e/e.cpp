#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

template <class T>
struct Matrix
{
    vector<vector<T>> A;

    Matrix() {}

    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}

    Matrix(size_t n) : A(n, vector<T>(n, 0)){};

    size_t height() const
    {
        return (A.size());
    }

    size_t width() const
    {
        return (A[0].size());
    }

    inline const vector<T> &operator[](int k) const
    {
        return (A.at(k));
    }

    inline vector<T> &operator[](int k)
    {
        return (A.at(k));
    }

    static Matrix I(size_t n)
    {
        Matrix mat(n);
        for (int i = 0; i < n; i++)
            mat[i][i] = 1;
        return (mat);
    }

    Matrix &operator+=(const Matrix &B)
    {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i][j] += B[i][j];
        return (*this);
    }

    Matrix &operator-=(const Matrix &B)
    {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i][j] -= B[i][j];
        return (*this);
    }

    Matrix &operator*=(const Matrix &B)
    {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }

    Matrix &operator^=(long long k)
    {
        Matrix B = Matrix::I(height());
        while (k > 0)
        {
            if (k & 1)
                B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
    }

    Matrix operator+(const Matrix &B) const
    {
        return (Matrix(*this) += B);
    }

    Matrix operator-(const Matrix &B) const
    {
        return (Matrix(*this) -= B);
    }

    Matrix operator*(const Matrix &B) const
    {
        return (Matrix(*this) *= B);
    }

    Matrix operator^(const long long k) const
    {
        return (Matrix(*this) ^= k);
    }

    friend ostream &operator<<(ostream &os, Matrix &p)
    {
        size_t n = p.height(), m = p.width();
        for (int i = 0; i < n; i++)
        {
            os << "[";
            for (int j = 0; j < m; j++)
            {
                os << p[i][j] << (j + 1 == m ? "]\n" : ",");
            }
        }
        return (os);
    }

    T determinant()
    {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++)
        {
            int idx = -1;
            for (int j = i; j < width(); j++)
            {
                if (B[j][i] != 0)
                    idx = j;
            }
            if (idx == -1)
                return (0);
            if (i != idx)
            {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++)
            {
                B[i][j] /= vv;
            }
            for (int j = i + 1; j < width(); j++)
            {
                T a = B[j][i];
                for (int k = 0; k < width(); k++)
                {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};

using mint = modint998244353;
using Mat = Matrix<mint>;
using vm = vector<mint>;

int H, W, K;
int sy, sx, gy, gx;

void solve()
{
    cin >> H >> W >> K >> sx >> sy >> gx >> gy;
    Mat A(4, 4);
    Mat X(4, 1);
    if(sx != gx && sy != gy){
        X[0][0] = 1;
    }
    if(sx != gx && sy == gy){
        X[1][0] = 1;
    }
    if(sx == gx && sy != gy){
        X[2][0] = 1;
    }
    if(sx == gx && sy == gy){
        X[3][0] = 1;
    }

    int H1 = H - 1;
    int H2 = H - 2;
    int W1 = W - 1;
    int W2 = W - 2;
    int _A[4][4] = {
        {H2 + W2, W1, H1, 0},
        {1, H2, 0, H1},
        {1, 0, W2, W1},
        {0, 1, 1, 0},
    };
    rep(h, 4){
        rep(w, 4){
            A[h][w] = _A[h][w];
        }
    }

    A ^= K;
    Mat ans = A * X;

    cout << ans[3][0].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}