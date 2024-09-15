#include <bits/stdc++.h>
using namespace std;
 
/*
	Detecting cycle in Graph
	Cycle => Between two given pair of nodes, there exist more than one path
 
	   1-------2
	   |       |
	   |       |
	   4-------3
 
	   Parent = If dfs call to node v comes from node u, then u can be considered as parent of v.
	   Just having the information of number of vertices and edges is not sufficient
	   to tell whether a graph contains cycle or not.
 
*/
 

bool dfs(int node, int parent, vector<bool>& vis, vector<int> adj[]) {
    vis[node] = true;

    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) {
            if(dfs(neighbour, node, vis, adj)) {
                return true;
            }
        } else {
            if(neighbour != parent) return true;
        }
    }
    return false;
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
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    bool hasCycle = false;
    // handling disconnected components
    for(int i=0; i<n; i++) {
    	if(!vis[i]) {
    		if(dfs(i, -1, vis, adj)) {
                hasCycle = true;
                break;
            }
    	}
    }
    cout << hasCycle << "\n";
    return 0;
}


/*
    1---------2
    |         |
    |         |
    |         |
    4---------3

    cycle = true
*/

/*

    1---------2
              |
              |
              |
    4---------3

    cycle  = false
*/