#include <bits/stdc++.h>
using namespace std;

void Bellman_Ford(vector<pair<char, pair<char, int>>> Edge, set<char> unique_vertices, char source, int ne)
{
    int M = 90;
    int dist[M + 1];

    for (int u = 0; u <= M; u++)
    {
        dist[u] = INT_MAX;
    }
    dist[source] = 0;

    int n = unique_vertices.size();

    for (int i = 1; i <= n - 1; i++)
    {
        for (int k = 0; k <= ne - 1; k++)
        {
            pair<char, pair<char, int>> e = Edge[k];
            int u = e.first;
            int v = e.second.first;
            int w = e.second.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    cout << "\nShortest distances from source " << source << ":\n";
    auto it = unique_vertices.begin();
    while (it != unique_vertices.end())
    {
        char c = *it;
        if (dist[c] == INT_MAX)
        {
            cout << c << ": INF\n";
        }
        else
        {
            cout << c << ": " << dist[c] << "\n";
        }

        ++it;
    }
}

int main()
{
    int ne;
    cout << "Enter Number of Edges: ";
    cin >> ne;

    vector<pair<char, pair<char, int>>> Edge;
    set<char> unique_vertices;

    for (int i = 0; i < ne; i++)
    {
        char u, v;
        int w;
        cout << "Enter vertices u and v and weight:";
        cin >> u >> v >> w;
        Edge.push_back(make_pair(u, make_pair(v, w)));
        unique_vertices.insert(u);
        unique_vertices.insert(v);
    }
    char source;
    cout << "Enter Source: ";
    cin >> source;
    Bellman_Ford(Edge, unique_vertices, source, ne);

    return 0;
}