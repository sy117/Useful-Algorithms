#include <bits/stdc++.h>
using namespace std;
 
/*
	TopologicalSorting:- Linear ordering of vertices such that if there is an edge
    form u to v then, u appears before v in ordering

    NOTE:- Applicable only for DAG(Directed Acyclic Graph)

    Approach:- Why DFS works in this case is because if there is a directed edge 
    from u to v (u -> v) and dfs call to v goes through u then dfs(v) will be
    completed first and then dfs(u)
	
*/
 

void dfs(int node, vector<bool>& vis, vector<int>& topo, vector<int> adj[]) {
    vis[node] = true;

    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) {
           dfs(neighbour, vis, topo, adj);
        }
    }
    topo.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int u, v;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        u--; v--; // 0-based indexing
        adj[u].push_back(v);
    }

    vector<bool> vis(n, false);
    vector<int> topo;
    // handling disconnected components
    for(int i=0; i<n; i++) {
    	if(!vis[i]) {
            dfs(i, vis, topo, adj);
        }
    }
    reverse(topo.begin(), topo.end());

    for(int v: topo) {
    	cout << v << " ";
    }
    cout << endl;
    
    return 0;
}