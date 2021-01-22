#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj, vector<bool> &visited, int sn)
{
    stack<int> s;
    s.push(sn);

    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();

        if (!visited[tmp])
        {
            cout << tmp << " ";
            visited[tmp] = true;
        }

        for (auto n : adj[tmp])
        {
            if (!visited[n])
                s.push(n);
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
    cout << "Enter vertex from where to perform DFS : ";
    cin >> s;
    DFS(adj, visited, s);
    return 0;
}