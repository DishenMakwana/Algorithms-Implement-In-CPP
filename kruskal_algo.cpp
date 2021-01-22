#include <bits/stdc++.h>
using namespace std;

// Find set of vertex i
int find(int i, int parent[])
{

    /*while (parent[i] != i) if u set parent like [0,1,2,3,...]
        i = parent[i]; 
    return i;*/

    if (parent[i] == -1)
        return i;
    return find(parent[i], parent);
}

void Union(int i, int j, int parent[])
{
    int a = find(i, parent);
    int b = find(j, parent);
    if (a != b)
        parent[b] = a;
}

void kruskal_algo(vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++) // set 0 value elements to INFINITE
    {
        for (int j = 0; j < adj.size(); j++)
        {
            if (adj[i][j] == 0)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

    int mincost = 0;
    int parent[adj.size()] = {0};

    for (int i = 0; i < adj.size(); i++)
        parent[i] = -1;

    int edge_count = 0;

    while (edge_count < adj.size() - 1) // total edge = total number of elements - 1;
    {
        int min = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (find(i, parent) != find(j, parent) && adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        Union(a, b, parent); // Add this nodes into tree
        cout << "Edge-" << ++edge_count << " :(" << a << "," << b << ") cost->" << min << endl;
        mincost += min;

        /*for(int i=0;i<adj.size();i++) // watch, how parent is set
            cout << parent[i] << " ";
        cout << endl;*/
    }

    cout << endl
         << "Minimum cost -> " << mincost << endl;
}

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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    //print_matrix(adj);
    kruskal_algo(adj);
    return 0;
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

/*8
0 1 7 0 0 0 0 0
1 0 0 5 6 0 0 0
7 0 0 2 0 0 0 0
0 5 2 0 0 0 0 0
0 6 0 0 0 3 9 0
0 0 0 0 3 0 0 8
0 0 0 0 9 0 0 4
0 0 0 0 0 8 4 0
ans = 29
parent = [-1, 0, 0, 2, 0, 4, 0, 6]
*/