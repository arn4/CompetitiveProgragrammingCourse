
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We try to color the graph nodes with two colors such that every edge 
 * has two distic colors. If we find a contradiction the graph isnt 
 * bipartite, otherwise yes.
 * Since we use a DFS and matrix to store the graph, the complexity is 
 * O( V^2 ) both in time and space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}



int color[MAX];
vector <int> graph[MAX];

bool dfs( int v, int c, const int& V ) {
	color[v] = c;
	
	for( auto u: graph[v] ) {
		if( color[u] == 0 ) {
			if ( dfs( u, c * (-1), V) == false ) return false;
		} else if ( color[u] == c ) {
			return false;
		}
			
	}
	
	return true;
}

bool isBipartite(int G[][MAX], int V) {
	
     fill( color, color + V, 0 ); // Reset the coloring
     for( int i = 0; i < V; i++  ) graph[i].clear(); // Clear the graph
     
     // Building the adiacenty list
     for( int i = 0; i < V; i++ ) 
		for( int j = 0; j < V; j++ ) if( G[i][j] == 1 ) {
			graph[i].push_back( j );
		}
		
	for( int i = 0; i < V; i++ ) if( color[i] == 0 ) {
		if( not dfs( i, 1, V )  ) return false;
	}
    
    return true;
}

