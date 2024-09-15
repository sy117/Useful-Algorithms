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
 

bool detectCycle(int startNode, vector<bool>& vis, vector<int> adj[]) {

    queue<pair<int, int> > qu; // {node, parent}
    qu.push({startNode, -1});
    vis[startNode] = true;
    while(!qu.empty()) {
        auto [node, parent] = qu.front();
        qu.pop();

        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) {
                vis[neighbour] = true;
                qu.push({neighbour, node});
            } else {
                if(neighbour != parent) return true;
            }
        }
    }
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
    	if(!vis[i] && !hasCycle) {
    		hasCycle = detectCycle(i, vis, adj);
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

    cyclye = true
*/

/*

    1---------2
              |
              |
              |
    4---------3

    cycle  = false
*/