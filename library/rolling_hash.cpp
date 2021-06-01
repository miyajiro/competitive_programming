#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

template <unsigned mod>
struct RollingHash
{
    vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const
    {
        unsigned long long x = (unsigned long long)a * b;
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        asm("divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 10007)
    {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++)
        {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod)
                hashed[i + 1] -= mod;
        }
    }

    /**
     * 区間[l, r) のハッシュ値を返す
     * O(1)
     */
    unsigned get(int l, int r) const
    {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod)
            ret -= mod;
        return ret;
    }

    /**
     * ハッシュ値h1と長さh2lenのハッシュ値h2を結合する
     * O( log N )
     */
    unsigned connect(unsigned h1, int h2, int h2len) const
    {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod)
            ret -= mod;
        return ret;
    }

    /**
     * LCP (Longest Common Prefix)
     * 区間[l1, r1)とハッシュテーブルがbからなる区間[l2, r2]の文字列の最長共通接頭辞の長さを求める
     * O( log N )
     */
    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2)
    {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};

using RH = RollingHash<1000000007>;
