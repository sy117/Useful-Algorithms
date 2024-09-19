#include <bits/stdc++.h>
using namespace std;
 
/*
	Detecting cycle in Directed Graph
	Cycle => A node is reachable to itself through same path
 
	   1------>2
	   ^       |
	   |       v
	   4<------3

       Approach:- use two visited array one for node visited and other for node visited in same path

       vis[node] = 0 => node is not visited
       vis[node] = 1 => node is visited but through some different path
       vis[node] = 2 => node is visisted through same path 
 
*/
 

bool dfs(int node, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 2;

    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) {
            if(dfs(neighbour, vis, adj)) {
                return true;
            }
        } else {
            if(vis[neighbour] == 2) return true;
        }
    }
    vis[node] = 1;
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
    }
    vector<int> vis(n, 0);
    bool hasCycle = false;
    // handling disconnected components
    for(int i=0; i<n; i++) {
    	if(!vis[i]) {
    		if(dfs(i, vis, adj)) {
                hasCycle = true;
                break;
            }
    	}
    }
    cout << hasCycle << "\n";
    return 0;
}


/*
Example tese case:-
10 11
1 2
2 3
3 4
4 5
5 6
3 7
7 5
8 2
8 9
9 10
10 8
*/