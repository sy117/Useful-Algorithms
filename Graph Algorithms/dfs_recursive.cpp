/*
	Graph Traversal: Depth First Search(recursive)
	Useful Link:- https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool vis[N];

void dfs(int src)
{
	cout<<src<<"\n";
	vis[src]=true;
	for(auto x: adj[src])
	{
		if(!vis[x])
		{
			dfs(x);
		}
	}
}


int main()
{
	// n = vertices, m=edges
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis, false,sizeof(vis));
	dfs(1);
	return 0;
}

/*

			1
		   / \
		  2   3
		 /     \
		4       5
		    
	INPUT:
	5 4
	1 2
	1 3
	2 4
	3 5
	OUTPUT:
	1
	2
	4
	3
	5
*/