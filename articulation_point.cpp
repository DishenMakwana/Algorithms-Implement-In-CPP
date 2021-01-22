#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define NODE 1000
typedef pair<int, int> Pair;

vector<int> adjacent[NODE];
vector<Pair> bridges;
set<int> points;
int parent[NODE] = {-1};
int discTime[NODE] = {0};
int low[NODE] = {0};
int counter = 0;
bool visit[NODE] = {false};

void articulation(int node)
{
    /* update the visiting status for the node*/
    visit[node] = true;

    /* increase the timer and update the discover and lower time for this node*/
    counter++;
    discTime[node] = counter;
    low[node] = counter;

    /* this will count the child number of the node */
    int child = 0;

    for (int i = 0; i < adjacent[node].size(); i++)
    {
        /* access all the adjacent of the node */
        int thisnode = adjacent[node][i];

        /* checking whether this node is already visited or not */
        if (!visit[thisnode])
        {
            /* increase the child number of the node */
            child++;

            /* update this child parent and pass this child for next checking */
            parent[thisnode] = node;
            articulation(thisnode);

            /* condition for articulation path */
            if (low[thisnode] > discTime[node])
            {
                bridges.push_back(make_pair(node, thisnode));
            }

            /* condition for articulation node */
            if (parent[node] == -1 && child > 1)
            {
                points.insert(node);
            }
            else if (parent[node] != -1 && low[thisnode] >= discTime[node])
            {
                points.insert(node);
            }

            /* update the lowest time to reach the node */
            low[node] = min(low[node], low[thisnode]);
        }
        /* update the lowest time with this condition :: for visited adjacent*/
        else if (thisnode != parent[node])
            low[node] = min(low[node], discTime[thisnode]);
    }
}

void display_nodes()
{
    cout << "Articulation Point : ";
    for (auto i : points)
        cout << i << " ";
    cout << endl;
}

void display_bridges()
{
    cout << "Articulation Bridges : " << endl;
    for (int i = 0; i < bridges.size(); i++)
        cout << "\t" << bridges[i].first << " --- " << bridges[i].second << endl;
}

int32_t main()
{
    IOS;
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int node1;
        int node2;
        cin >> node1 >> node2;

        adjacent[node1].push_back(node2);
        adjacent[node2].push_back(node1);
    }

    articulation(0);
    display_nodes();
    display_bridges();
}

/*
5 5
1 0
0 2
2 1
0 3
3 4
Articulation Point : 0 3
Articulation Bridges :
        3 --- 4
        0 --- 3
*/