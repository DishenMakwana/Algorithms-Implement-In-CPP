#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);

stack<int> s;

void DFS(vector<vector<int>> &adj, bool visited[], int i)
{
	visited[i] = true;
	for (int j = 0; j < adj[i].size(); j++)
	{
		int node = adj[i][j];
		if (!visited[node])
			DFS(adj, visited, node);
	}
	s.push(i);
}

void topological_sort(vector<vector<int>> &adj)
{
	bool visited[adj.size()];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < adj.size(); i++)
	{
		if (!visited[i])
			DFS(adj, visited, i);
	}
	cout << "Topological Sort of given Graph : ";
	for (int i = 0; i < adj.size(); i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
}

int32_t main()
{
	int e;
	cout << "Enter no. of Edges : ";
	cin >> e;
	vector<vector<int>> adj;
	adj.resize(e);

	for (int j = 0; j < e; j++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	topological_sort(adj);
}
/*
Enter no. of Edges : 6
5 2
5 0
4 0
4 1
2 3
3 1
Topological Sort of given Graph : 5 4 2 3 1 0
*/