#include <bits/stdc++.h>
using namespace std;
 
/*
	Approach:- 1. Find topological sorting 
			   2. process nodes one by one in same order as the appear in topo sort
			   3. relax all the edges passing through current node
	
	Time Complexity:- O(V + E)

	Why this approach works ?

	- Processing the vertices in topological order ensures that by the time you
	  get to a vertex, you've already processed all the vertices that can precede
	  it

	Dijkstr's shortest path algorithm will also work here
	Time Complexity:- O(ElogV)

*/

 
vector<int> topoSort(int n, vector<pair<int,int>> adj[]) {
    vector<int> inDegree(n, 0);
    for(int u=0; u<n; u++) {
        for(auto v: adj[u]) {
            inDegree[v.first]++;
        }
    }
    queue<int> qu;
    for(int i=0; i<n; i++) {
        if(inDegree[i] == 0) {
            qu.push(i);
        }
    }
    vector<int> res;
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        res.push_back(node);
        for(auto ch: adj[node]) {
            inDegree[ch.first]--;
            if(inDegree[ch.first] == 0) {
                qu.push(ch.first);
            }
        }
    }

    return res;
}

vector<int> shortestPath(int src, int n, vector<pair<int,int>> adj[]) {
    const int INF  = 1e9;
    vector<int> topo = topoSort(n, adj);
    vector<int> dist(n, INF);
    dist[src] = 0;
    for(int i=0; i<n; i++) {
        int node = topo[i];
        for(auto [adjNode, wt]: adj[node]) {
            if(dist[node] + wt < dist[adjNode]) {
                dist[adjNode] = dist[node] + wt;
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int source = 0;
    vector<int> dist = shortestPath(source, n, adj); // source = 0

    for(int i=0; i<n; i++) {
        cout << "Shortest distance from: " << source << " to: " << i <<" = " << dist[i] << "\n";
    }

    return 0;
}

/*
    Example TC:-
    5 6
	0 1 2
	0 2 3
	1 4 8
	2 3 1
	2 4 4
	3 1 1

    Output:- dist = [0, 2, 3, 4, 7]
*/


