#include <bits/stdc++.h>
using namespace std;

int min_dist(int dist[], bool sptSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void print_path(int parent[], int x)
{
    if (parent[x] == -1)
        return;

    print_path(parent, parent[x]);
    cout << x << " ";
}

void print_ans(int dist[], int n, int parent[], int src)
{
    cout << "Vertex\t Distance\t Path" << endl;
    ;
    for (int i = 1; i < n; i++)
    {
        cout << src << " -> " << i << " \t\t " << dist[i] << "\t\t   " << src << " -> ";
        print_path(parent, i);
        cout << endl;
    }
}

void dijkstra_algo(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    int dist[n];
    bool sptSet[n];
    int parent[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX; // set distance to INFINITE
        sptSet[i] = false; // set all elements to not selected
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = min_dist(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v]) < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    print_ans(dist, graph.size(), parent, src);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    dijkstra_algo(graph, 0);
    return 0;
}

/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0  
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0 

Ans :=>
Vertex   Distance    Path
0 -> 1      4        0 -> 1 
0 -> 2      12       0 -> 1 2 
0 -> 3      19       0 -> 1 2 3 
0 -> 4      21       0 -> 7 6 5 4 
0 -> 5      11       0 -> 7 6 5 
0 -> 6      9        0 -> 7 6 
0 -> 7      8        0 -> 7 
0 -> 8      14       0 -> 1 2 8 
*/