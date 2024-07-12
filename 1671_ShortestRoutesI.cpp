#include <iostream>
#include <vector>
using namespace std;

class WeightedDirectedGraph
{
    struct Edge
    {
        int vertex;
        int weight;
    };

    // Adjacency list representation
    vector<vector<Edge>> adj;

  public:
    WeightedDirectedGraph(int sz) : adj(sz) {}

    // Adds a weighted directed edge from u->v
    void add(int u, int v, int w)
    {
        // Convert from 1 indexed to 0 indexed
        --u;
        --v;
        if (u < 0 || u >= adj.size() || v < 0 || v >= adj.size())
            throw std::out_of_range("Invalid vertex number");
        adj[u].push_back({v, w});
    }

    const vector<Edge> &adjacent(int u) const
    {
        --u;
        if (u < 0 || u >= adj.size())
            throw std::out_of_range("Invalid vertex number");
        return adj[u];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    WeightedDirectedGraph g(n);

    for (int i = 0; i < m; i++)
    {
        int t1, t2, w;
        cin >> t1 >> t2 >> w;
        g.add(t1, t2, w);
    }

}