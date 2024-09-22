#include <bits/stdc++.h>
using namespace std;
 
/*
	TopologicalSorting:- Linear ordering of vertices such that if there is an edge
    form u to v then, u appears before v in ordering

    NOTE:- Applicable only for DAG(Directed Acyclic Graph)

    Kahn's Algorithm:- Uses BFS + Indegree concept to find topological sorting
	
*/
 

vector<int> topoSort(int n, vector<int> adj[]) {
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
    vector<int> res;
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        res.push_back(node);
        for(auto ch: adj[node]) {
            inDegree[ch]--;
            if(inDegree[ch] == 0) {
                qu.push(ch);
            }
        }
    }

    return res;
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

    vector<int> topo = topoSort(n, adj);

    for(int v: topo) {
    	cout << v << " ";
    }
    cout << endl;
    
    return 0;
}

/*
    Example TC:-
    6 6
    6 1
    5 2
    6 3
    3 4
    4 2
    5 2

    Output:- [4 5 0 2 3 1]
*/