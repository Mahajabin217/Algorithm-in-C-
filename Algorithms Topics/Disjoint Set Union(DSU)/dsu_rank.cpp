#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int grp_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1; // sbai ke -1 kore rekhlm
        grp_size[i] = 1;
        level[i]=0;
    }
}
int dsu_find(int node) // O(logN)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(level[leaderA] > level[leaderB])
    {
        par[leaderB]=leaderA; // B sacrifice krbe
    }
    else if(level[leaderB] > level[leaderA])
    {
        par[leaderA]=leaderB; // A sacrifice krbe
    }
    else 
    {
        par[leaderA]=leaderB; // je kono ek jon sacrifice korlei hobe
        level[leaderB]++;
    }
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (grp_size[leaderA] > grp_size[leaderB])
    {
        par[leaderB] = leaderA;
        grp_size[leaderA] += grp_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        grp_size[leaderB] += grp_size[leaderA];
    }
}
int main()
{
    dsu_initialize(7);
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    
    return 0;
}