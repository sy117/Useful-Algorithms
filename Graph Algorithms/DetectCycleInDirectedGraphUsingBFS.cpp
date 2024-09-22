#include <bits/stdc++.h>
using namespace std;
 
/*
	Detecting cycle in Directed Graph
	Cycle => A node is reachable to itself through same path
 
	   1------>2
	   ^       |
	   |       v
	   4<------3

    Approach:- Since topological sorting works only for Directed Acyclic Graph, we can use
    this idea to detect cycle in directed graph.

    If the toposort array doesn't contain all the nodes, that mean graph contains cycle
 
*/
 
bool checkCycleInGraph(int n, vector<int> adj[]) {
    vector<int> inDegree(n, 0);
    for(int u=0; u<n; u++) {
        for(auto v: adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> qu;
    for(int i=0; i<n; i++) {
        if(inDegree[i] == 0) {
            qu.push(i);
        }
    }
    int cnt = 0;
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        cnt++;

        for(auto ch: adj[node]) {
            inDegree[ch]--;
            if(inDegree[ch] == 0) {
                qu.push(ch);
            }
        }
    }

    return (cnt == n);
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
    cout << "Graph contains cycle: " << checkCycleInGraph(n, adj) << "\n";
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