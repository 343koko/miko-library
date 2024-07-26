#ifndef MIKO_TREE_HPP
#define MIKO_TREE_HPP 1

#include <cassert>
#include <queue>

namespace miko
{
    template <typename G> struct tree
    {
        using E = typename G::edge_type;

    public:
        tree(G g, int r) : r(r), g(g)
        {
            assert(g.edge_size() == g.size() - 1);
            assert(g.is_undirected());
            init();
        }

        E parent(int u)
        {
            return par[u];
        }

        int size(int u)
        {
            return sz[u];
        }

        inline std::vector<E> &operator[](const int &u)
        {
            return child[u];
        }

        inline const std::vector<E> &operator[](const int &u) const
        {
            return child[u];
        }
    
    protected:
        void add_child(int u, E e)
        {
            child[u].push_back(e);
            add_size(u, e);
        }

        void add_parent(int u, E e)
        {
            par[u] = e;
            culc_and_set_depth(u, e);
        }

        // e は親
        void culc_and_set_depth(int u, E e)
        {
            dpt[u] = dpt[e.to] + 1;
        }

        void init_size(int u)
        {
            sz[u] = 1;
        }

        // e は子
        void add_size(int u, E e)
        {
            sz[u] += sz[e.to];
        }

    private:
        int r;
        std::vector<int> dpt;
        std::vector<int> sz;
        std::vector<E> par;
        std::vector<std::vector<E>> child;
        G g;

        void init()
        {
            int n = g.size();
            dpt.resize(n);
            sz.resize(n);
            par.resize(n);
            child.resize(n);
            std::vector<int> used(n);

            auto add_child_recursive = [&](auto self, int u) -> void
            {
                used[u] = true;
                init_size(u);
                for (E e : g[u])
                {
                    if (used[e.to])
                    {
                        add_parent(u, e);
                    }
                    else
                    {
                        self(self, e.to);
                        add_child(u, e);
                    }
                }
            };

            used[r] = true;
            add_child_recursive(add_child_recursive, r);
        }
    };

}  // namespace miko

#endif  // MIKO_TREE_HPP
