
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The grid is reduced to a graph where nodes are the Xs and there's 
 * an edge between two adiacent Xs. The task is now to count connected 
 * components of the graph, wich is done with a DFS.
 * Complexity: O( T * ( N * M ) ) in time and O( N * M ) in space.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 50

int T;
int N, M;
char G[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs( int i, int j ) {
	
	if( G[i][j] == 'O' ) return;
	
	visited[i][j] = true;
	
	if( i != N - 1 and not visited[i+1][j] ) dfs( i + 1, j );
	if( i != 0 and not visited[i-1][j] ) dfs( i - 1, j );
	if( j != M - 1 and not visited[i][j+1] ) dfs( i, j + 1 );
	if( j != 0 and not visited[i][j-1] ) dfs( i, j - 1) ;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> T;
	
	while( T-- ) {
		cin >> N >> M;
		
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ )
				cin >> G[i][j];
		
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ ) 
				visited[i][j] = false;
		
		int c = 0;
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ ) 
				if( not visited[i][j] and G[i][j] == 'X' ) {
					dfs( i, j );
					c++;
				}
		cout << c << endl;	
		
	}
	
	return 0;
}
