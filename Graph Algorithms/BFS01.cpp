/*
      Algorithm:- 0-1 BFS
      Useful Link:- https://codeforces.com/blog/entry/22276
      
      Time Complexity:- Dijkstra = O(E + VlogV)
                        01BFS = O(E + V)
*/

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
     
typedef vector<int> VI;
typedef pair<int,int> PI;

const int INF = 1e9;
const int N = 1e5 + 5;

vector<PI> edge[N];
int dist[N];

void in_it()
{
	for(int i=0;i<N;i++)
	{
		dist[i]=INF;
	}
}
void bfs0_1 (int src)
{
	in_it();
	deque<int> dq;
	dq.push_front(src);
	dist[src]=0;
	while(!dq.empty())
	{
		int u = dq.front();
		dq.pop_front();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first;
			int w=edge[u][i].second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(w==0)
				{
					dq.push_front(v);
				}
				else
				{
					dq.push_back(v);
				}
			}
		}
	}
}

int main() 
{
	// n- vertices, e-edges
	int n,e;
	cin>>n>>e;
	int u,v,w;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		edge[u].pb({v,w});
		edge[v].pb({v,w});
	}
	bfs0_1(0);
	for(int i=0;i<n;i++)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
}
/*
INPUT:
9 14
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
6 8 1
7 8 1

OUTPUT:
0 0 1 1 2 1 2 1 2

EXAMPLE GRAPH: https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/

*/