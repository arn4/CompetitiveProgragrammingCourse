
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We count the number of emploies who don't know any language, this will
 * be added to the final answer. Then we build a graph where nodes are 
 * languages, and there's a node between two of them only if exists an employ
 * who speaks both. The problems is now reduced to count the number of edges
 * needed to connect the graph of languages spoken by at least one employ.
 * Complexity: O(n*m+m) in time and O( n*m ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXM 100

int n, m;
bool edges[MAXM+1][MAXM+1]; // Check to not insert same edges twice
bool used[MAXM+1];
vector <int> G[MAXM+1];
int l;
int lang[MAXM+1];
int no_lang = 0; // emploies with no language

// Insert an edge in the graph
void make_edge( int x, int y ) {
	if( not edges[x][y] ) {
		G[x].push_back( y );
		G[y].push_back( x );
		edges[x][y] = true;
		edges[y][x] = true;
		//cout << "Edge: " << x << ' ' << y << endl;
	}
}

bool visited[MAXM+1];
void dfs( int v ) {
	visited[v] = true;
	
	for( auto u: G[v] ) {
		if( not visited[u] )
			dfs( u );
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n >> m;
	
	// Build the graph 
	while( n-- ) {
		cin >> l;
		if( l == 0 ) no_lang++;
		for(int i = 0; i < l; i++ ) {
			cin >> lang[i];
			used[lang[i]] = true;
			for( int j = 0; j < i ; j++ ) 
				make_edge( lang[i], lang[j] );
		}
	}
	
	int cc = 0;
	for( int v = 1; v <= m; v++ ) if( used[v] and not visited[v] ) {
		dfs( v );
		cc++;
	}
		
	cout << (cc == 0 ? 0 : cc - 1 ) + no_lang << endl;
	
	return 0;
}
