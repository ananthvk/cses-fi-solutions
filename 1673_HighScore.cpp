#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;

struct Edge
{
    long long int vertex;
    long long int weight;
};

// incident[u], has all edges incident on u
vector<vector<Edge>> incident;
map<long long int, long long int> dp;

long long int max_score(long long int i)
{
    if (i <= 1)
    {
        return 0;
    }
    if (dp.find(i) != dp.end())
    {
        return dp[i];
    }
    long long int max_current = numeric_limits<long long int>::min();
    for (const auto &e : incident[i])
    {
        max_current = max(max_current, max_score(e.vertex) + e.weight);
    }
    dp[i] = max_current;
    return max_current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, m;
    cin >> n >> m;

    incident.resize(n + 1);


    // Here is a DP solution I formulated,
    // Subproblem: Find the maximum score to a given room (vertex)
    // Recurrence relation: max_score(v) = max(max_score(i) for i incident on v)
    // Subproblem size: |E| (All edges are incident on this vertex)
    // Running size: O(|E||V|)
    // Reverse the directed graph, i.e. if u->v, store it as u<-v

    for (long long int i = 0; i < m; i++)
    {
        long long int t1, t2, w;
        cin >> t1 >> t2 >> w;
        incident[t2].push_back({t1, w});
    }
    cout << max_score(n) << endl;
}
