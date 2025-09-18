#include<bits/stdc++.h>
using namespace std;

int M = 100;

void Dijkstra(vector<pair<int,int> > G[], int source)
{
    int Dist[M+1];
    for(int u = 0; u <= M; u++)
    {
        Dist[u] = INT_MAX;
    }
    Dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > PQ;
    PQ.push(make_pair(0, source));

    while(!PQ.empty())
    {
        pair<int,int> u = PQ.top();
        PQ.pop();

        int dist_u = u.first;
        int vertex = u.second;

        if(dist_u > Dist[vertex])
            continue;

        int l = G[vertex].size();
        for(int i = 0; i < l; i++)
        {
            pair<int,int> v = G[vertex][i];
            int adj_vertex = v.first;
            int weight = v.second;

            if(Dist[vertex] + weight < Dist[adj_vertex])
            {
                Dist[adj_vertex] = Dist[vertex] + weight;
                PQ.push(make_pair(Dist[adj_vertex], adj_vertex));
            }
        }
    }


    for(int i = 0; i <= M; i++)
    {
        if(Dist[i] != INT_MAX)
            cout << "Distance from " << source << " to " << i << " is " << Dist[i] << endl;
        else
            cout << "Distance from " << source << " to " << i << " is INF" << endl;
    }
}

int main()
{
    int ne;
    cin >> ne;

    vector<pair<int,int> > G[M+1];
    for(int i = 1; i<=ne; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    int source;
    cin >> source;

    Dijkstra(G,source);

    return 0;
}
