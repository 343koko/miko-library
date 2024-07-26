#ifndef MIKO_MODINT_HPP
#define MIKO_MODINT_HPP 1

#include <atcoder/modint>

namespace miko
{

    template <int m> struct static_modint : atcoder::static_modint<m>
    {
        using mint = static_modint;

    public:
        static_modint() {}

        static_modint(long long v) : atcoder::static_modint<m>(v) {}

        friend std::ostream &operator<<(std::ostream &os, const mint &x)
        {
            return os << x.val();
        }

        friend std::istream &operator>>(std::istream &is, mint &s)
        {
            long long v;
            is >> v;
            s = mint(v);
            return is;
        }
    };
    

}  // namespace miko

#endif  // MIKO_MODINT_HPP
