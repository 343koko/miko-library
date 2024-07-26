#ifndef MIKO_DIJKSTRA_HPP
#define MIKO_DIJKSTRA_HPP 1

#include <cassert>
#include <queue>

namespace miko
{

    template <typename G>
    std::vector<typename G::value_type> dijkstra(G &g, int s)
    {
        // T should be number.
        using T = typename G::value_type;
        using P = std::pair<T, int>;

        int n = g.size();
        assert(s >= 0 && s < n);
        std::vector<T> d(n, -1);
        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        d[s] = 0;
        que.push(P(d[s], s));
        while(que.size())
        {
            auto [dist, u] = que.top();
            que.pop();
            if (d[u] < dist)
            {
                continue;
            }
            for (auto e : g[u])
            {
                int v = e.to;
                if (d[v] == -1 || d[v] > d[u] + e.val)
                {
                    d[v] = d[u] + e.val;
                    que.push(P(d[v], v));
                }
            }
        }
        return d;
    }

}  // namespace miko

#endif  // MIKO_DIJKSTRA_HPP
