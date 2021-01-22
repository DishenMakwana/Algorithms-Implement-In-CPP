#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int find_min_vertex(bool visited[], int weight[], int n)
{
    int min_vtx = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min_vtx == -1 || weight[i] < weight[min_vtx]))
        {
            min_vtx = i;
        }
    }
    return min_vtx;
}

void prims_algo(vector<vector<int>> adjmtx)
{
    int n = adjmtx.size();
    int parent[n] = {0};
    bool visited[n] = {0}; //mstset
    int weight[n] = {0};   //key

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX; //infinite
    }

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        //find min vertex
        int min_v = find_min_vertex(visited, weight, n);
        visited[min_v] = true;

        for (int j = 0; j < n; j++)
        {
            if (adjmtx[min_v][j] != 0 && !visited[j] && adjmtx[min_v][j] < weight[j])
            {
                weight[j] = adjmtx[min_v][j];
                parent[j] = min_v;
            }
        }
    }

    int total_min_distance = 0;

    for (int i = 1; i < n; i++)
    {
        cout << "Edge-" << i << " :(" << parent[i] << "," << i << ") cost->" << weight[i] << endl;
        total_min_distance += weight[i];
    }
    cout << endl
         << "Minimum cost -> " << total_min_distance << endl;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    //print_matrix(adj);
    prims_algo(adj);
}

/*
6
0 3 0 0 4 7
3 0 5 0 0 8
0 5 0 4 0 6
0 0 4 0 2 8
4 0 0 2 0 5
7 8 6 8 5 0
ans=18
*/

/*
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
ans=16
*/