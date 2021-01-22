#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void BFS(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        cout << tmp << " ";

        for (auto i : adj[tmp])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int32_t main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int s;
    cout << "Enter vertex from where to perform BFS : ";
    cin >> s;
    BFS(adj, visited, s);
    return 0;
}