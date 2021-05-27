#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

#include <atcoder/modint>

// 二項係数ライブラリ
template <class mint, atcoder::internal::is_static_modint_t<mint> * = nullptr>
struct BinomialCoefficient
{
    vector<mint> fact_, inv_, finv_;
    constexpr BinomialCoefficient(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
    {
        int MOD = mint::mod();
        for (int i = 2; i < n; i++)
        {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr mint com(int n, int k) const noexcept
    {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr mint fact(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return fact_[n];
    }
    constexpr mint inv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return inv_[n];
    }
    constexpr mint finv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return finv_[n];
    }
};