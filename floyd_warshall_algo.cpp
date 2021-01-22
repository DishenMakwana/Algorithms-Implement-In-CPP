#include <bits/stdc++.h>
using namespace std;

void print_ans(vector<vector<int>> dist)
{
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
        {
            if (dist[i][j] == 100)
                cout << setw(5) << "INF"
                     << "   ";
            else
                cout << setw(5) << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

void floyd_warshall_algo(vector<vector<int>> &graph)
{
    vector<vector<int>> dist(graph.size(), vector<int>(graph.size(), 0));

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            /*if(graph[i][j]==100)
            {
               dist[i][j] = INT_MAX;
            }
            else
            {*/
            dist[i][j] = graph[i][j];
            //}
        }
    }

    for (int k = 0; k < graph.size(); k++)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph.size(); j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][j] != -1 && dist[i][k] != -1 && dist[k][j] != -1) // dist[i][j],k = min( (dist[i][k],k-1 + dist[k][j],k-1) , (dist[i][j],k-1))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    print_ans(dist);
}

int32_t main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter INFINITE dist as 100 value" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    floyd_warshall_algo(graph);
    return 0;
}

/*
 Enter INFINITE distance as 100 value
4
0 3 100 7
8 0 2 100
5 100 0 1
2 100 100 0 

Ans: 
       1        2       3       4
   +-------+--------+-------+-------+
1  |   0   |    3   |   5   |   6   |
2  |   5   |    0   |   2   |   3   |
3  |   3   |    6   |   0   |   1   |
4  |   2   |    5   |   7   |   0   |
   +-------+--------+-------+-------+ 
*/
