#include <iostream>
#include <miko/graph>
#include <miko/dijkstra>
using namespace std;
using namespace miko;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    graph<ll> g(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g.add_directed_edge(u, v, w);
    }
    vector<ll> d = dijkstra(g, s);
    cout << d[t] << endl;
}
