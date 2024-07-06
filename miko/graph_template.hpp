#ifndef MIKO_GRAPH_TEMPLATE_HPP
#define MIKO_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <vector>

namespace miko
{

    struct edge_template
    {
      public:
        int from;
        int to;

        edge_template(int from, int to)
        {
            this->from = from;
            this->to = to;
        }

        operator int() const
        {
            return to;
        }
    };

    template <typename E> struct graph_template
    {
      public:
        graph_template()
        {
            graph_template(0);
        }

        graph_template(int n)
        {
            this->n = n;
            g.resize(n);
        }

        void add_edge(E e)
        {
            g[e.from].push_back(e);
        }

        int size()
        {
            return n;
        }

        inline std::vector<E> &operator[](const int &k)
        {
            return g[k];
        }

        inline const std::vector<E> &operator[](const int &k) const
        {
            return g[k];
        }
    
      private:
        int n;
        std::vector<std::vector<E>> g;
    };

}  // namespace miko

#endif  // MIKO_GRAPH_TEMPLATE_HPP
