#include <bits/stdc++.h>
using namespace std;
 
/*
	Bipartite Graph:- A bipartite graph is a graph where the vertices can be divided into two 
    disjoint sets such that all edges connect a vertex in one set to a vertex in another set.
    There are no edges between vertices in the disjoint sets.

    How to check if the graph is Bipartite ?
    Approach:- If the graph can be coloured with two colours such that no two adjacent node
    have same colour, then the graph is Bipartite

    observations:-
    1. Graph with no cycle(liner graph), is always Bipertite
    2. Graph with even length cycle is always Bipertite
    3. Graph with odd length cycle will never be Bipertite
 
*/
 

bool checkBipertite(int startNode, int clr, vector<int>& colour, vector<int> adj[]) {

    queue<int > qu;
    qu.push(startNode);
    colour[startNode] = clr;
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();

        for(int neighbour: adj[node]) {
            if(colour[neighbour] == -1) {
                colour[neighbour] = 1 - clr;
                qu.push(neighbour);
            } else if(colour[neighbour] == colour[node]){
                return false;
            }
        }
    }
    return true;
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
    vector<int> colour(n, -1);
    bool isBipertite = true;

    // handling disconnected components
    for(int i=0; i<n; i++) {
    	if(colour[i] == -1) {
    		if(!checkBipertite(i, 0, colour, adj)) {
                isBipertite = false;
                break;
            }
    	}
    }
    cout << isBipertite << "\n";
    return 0;
}