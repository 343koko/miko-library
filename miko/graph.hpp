#ifndef MIKO_GRAPH_HPP
#define MIKO_GRAPH_HPP 1

#include <miko/graph_template>

namespace miko
{

    template <typename T = int> struct edge : public miko::edge_template
    {
    public:
        T val;

        edge() : edge_template() {}

        edge(int from, int to) : edge_template(from, to) {}

        edge(int from, int to, T val) : edge_template(from, to)
        {
            this->val = val;
        }
    };

    template <typename T = int> struct graph : public miko::graph_template<edge<T>>
    {
        using value_type = T;
        using edge_type = edge<T>;

    public:
        graph() : graph_template<edge<T>>()
        {
            is_dir = true;
            is_undir = true;
            m = 0;
        }

        graph(int n) : graph_template<edge<T>>(n)
        {
            is_dir = true;
            is_undir = true;
            m = 0;
        }

        void add_directed_edge(int from, int to)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to));
            is_undir = false;
            m++;
        }

        void add_directed_edge(int from, int to, T val)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to, val));
            is_undir = false;
            m++;
        }

        void add_undirected_edge(int from, int to)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to));
            graph_template<edge<T>>::add_edge(edge<T>(to, from));
            is_dir = false;
            m++;
        }

        void add_undirected_edge(int from, int to, T val)
        {
            graph_template<edge<T>>::add_edge(edge<T>(from, to, val));
            graph_template<edge<T>>::add_edge(edge<T>(to, from, val));
            is_dir = false;
            m++;
        }

        int edge_size()
        {
            return m;
        }

        bool is_directed()
        {
            return is_dir;
        }

        bool is_undirected()
        {
            return is_undir;
        }

    private:
        int m;
        bool is_dir;
        bool is_undir;
    };

}  // namespace miko

#endif  // MIKO_GRAPH_HPP
