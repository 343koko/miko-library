#ifndef MIKO_GRAPH_HPP
#define MIKO_GRAPH_HPP 1

#include <miko/graph_template>

namespace miko
{

    template <typename T = int> struct edge : public miko::edge_template
    {
      public:
        T val;

        edge(int from, int to) : edge_template(from, to) {}
        edge(int from, int to, T val) : edge_template(from, to)
        {
            this->val = val;
        }
    };

    template <typename T = int> struct graph : public miko::graph_template<edge<T>>
    {
      public:
        graph() : graph_template<edge<T>>() {}
        graph(int n) : graph_template<edge<T>>(n) {}

        void add_edge(int from, int to)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to));
        }

        void add_edge(int from, int to, T val)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to, val));
        }
    };

}  // namespace miko

#endif  // MIKO_GRAPH_HPP
