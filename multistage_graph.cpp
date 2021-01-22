#include <bits/stdc++.h>
using namespace std;

int shortestDist(vector<vector<int>> &graph, int n)
{
  int dist[n];
  dist[n - 1] = 0;

  for (int i = n - 2; i >= 0; i--)
  {
    dist[i] = 100; //INF

    for (int j = i; j < n; j++)
    {
      if (graph[i][j] == 100) //INF
        continue;

      dist[i] = min(dist[i], graph[i][j] + dist[j]);
    }
  }
  return dist[0];
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

  shortestDist(graph, n);
  return 0;
}
