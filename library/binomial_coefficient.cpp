#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

// 素数 p で割ったあまりに関する構造体 (特に p = 1000000007 とすることが多い)
template <int MOD>
struct ModInt
{
    long long val;
    constexpr ModInt(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr ModInt operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr ModInt operator+(const ModInt &r) const noexcept { return ModInt(*this) += r; }
    constexpr ModInt operator-(const ModInt &r) const noexcept { return ModInt(*this) -= r; }
    constexpr ModInt operator*(const ModInt &r) const noexcept { return ModInt(*this) *= r; }
    constexpr ModInt operator/(const ModInt &r) const noexcept { return ModInt(*this) /= r; }
    constexpr ModInt &operator+=(const ModInt &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const ModInt &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const ModInt &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) noexcept
    {
        return is >> x.val;
    }
    friend constexpr ModInt<MOD> modpow(const ModInt<MOD> &a, long long n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

// 二項係数ライブラリ
template <class T>
struct BinomialCoefficient
{
    vector<T> fact_, inv_, finv_;
    constexpr BinomialCoefficient(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
    {
        int MOD = fact_[0].getmod();
        for (int i = 2; i < n; i++)
        {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept
    {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T fact(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return finv_[n];
    }
};