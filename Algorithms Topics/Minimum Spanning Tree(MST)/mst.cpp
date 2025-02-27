#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int grp_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        grp_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (grp_size[leaderA] > grp_size[leaderB])
    {
        parent[leaderB] = leaderA;
        grp_size[leaderA] += grp_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        grp_size[leaderB] += grp_size[leaderA];
    }
}
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgelist;
    int totalCost = 0;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgelist.push_back(Edge(u, v, c));
    }
    sort(edgelist.begin(), edgelist.end(), cmp);
    for (Edge ed : edgelist)
    {
        // cout << ed.u << " " << ed.v << " " << ed.c << endl;
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.c;
        }
    }
    cout << totalCost << endl;
    return 0;
}