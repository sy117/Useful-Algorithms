#include <bits/stdc++.h>
using namespace std;

const int INF  = 1e9;
 
/*
	Dijkstra's Shortest Path Algorithm:-
 
	Key Highlights:- 
	1. Single source to all other destination shortest path
	2. Doesn't work in case edges having negative weight(or graph having negative cycle)
	3. Uses greedy approach
	4. Uses edge relaxation
	5. Time Complexity:- O(ElogV)
 
	Algo steps:-
	1. Initialize a Dist array to INF. Dist[source] = 0
	2. Maintain a data structure which returns the vertex 
		reachable from source vertex with min cost(greedly).
	3. While exploring connectivity of a vertex, do edge relaxation.
 

	  4    2
	1---2----3
	   3|    | 1
		4----5
		  2
 
	Dist = [0, INF, INF, INF, INF]
 
	DS: <{0, 1}>
----------------------------------------
 
	While DS.size() > 0:
		wt = DS.get().first
		u = Ds.get().second
		remove this entry from DS
		for adj[u]:
		 v = gg
		 wv = tt
		 perform edge relaxation and then do
		  DS.insert({dist[v], v})

    DS = Priority Queue (Min Heap)
    
    Algo deep dive:-
    1. Using Queue instead of PriorityQueue will also give correct result but in that case we
       will be unnecessarily exploring all the edges (not using greedy approach)
    2. Visited array in not reqired because in case of positive weight, if we go to v from u then again try
       to come back to u from v, cost will increase. Hence edge relaxation will not happen
    3. In case of negative cycle, above algorith will go into an infinite loop
    4. Set can be also used as the Data Structure and that we enable us to delete high cost edges from DS
       whenever required. Although it doesn't improve time complexity

*/		   
 
 
vector<int> shortestPathUsingDijkstrasAlgo(int src, int n, vector<pair<int,int>> adj[]) {
    const int INF  = 1e9;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight, node}
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto [wtSoFar, node] = pq.top();
        pq.pop();

        for(auto [adjNode, edgeWt]: adj[node]) {
            if(dist[node] + edgeWt < dist[adjNode]) {
                dist[adjNode] = dist[node] + edgeWt;
                pq.push({dist[adjNode], adjNode});
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
        adj[v].push_back({u, w});
    }
    int source = 0;
    vector<int> dist = shortestPathUsingDijkstrasAlgo(source, n, adj); // source = 0

    for(int i=0; i<n; i++) {
        cout << "Shortest distance from: " << source << " to: " << i <<" = " << dist[i] << "\n";
    }

    return 0;
}

/*
    Example TC:-
    5 6
	0 1 4
	0 2 3
	1 4 4
	1 2 2
	2 3 1
	4 2 5

    Output:- dist = [0, 4, 3, 4, 8]
*/

