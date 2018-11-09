
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We build the graph of the order comparing 2 consecutive words. Then, 
 * we check if it is a DAG: if yes we return the topological sort, if no
 *  we return Impossible.
 * Complexity: O( n ) both space and time.
*/


#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> S;
vector <int> graph[150]; // big enough for (char)'z'
bool edges[150][150]; // Check to not insert same edges twice
int visited[150];
string result;

bool dfs( int v ) {
	visited[v] = 1;
	
	for( auto u: graph[v] ) {
		if( visited[u] == 0 ) {
			if( not dfs( u ) ) {
				return false;
			}
		} else if( visited[u] == 1 ) return false;
	}
	
	visited[v] = 2;
	result.push_back( v );
	return true;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	S.resize( n );
	
	for( int i = 0; i < n; i++ ) {
		cin >> S[i];
		// Build the Graph
		if( i != 0 ) {
			for( unsigned int d = 0; d <= S[i].size() and d < S[i-1].size(); d++ ) {
				// If the word is a prefix of the precedent
				if( d == S[i].size() ) {
					cout << "Impossible" << endl;
					return 0;
				}
				
				if( S[i-1][d] != S[i][d] ) {
					if( not edges[ (int)S[i-1][d] ][(int)S[i][d] ] ) {
						edges[ (int)S[i-1][d] ][(int)S[i][d] ] = true;
						graph[ (int)S[i-1][d] ].push_back( (int)S[i][d] );
					}
					break;
				}
			}
		}
	}
	
	for( int i = (int)'a'; i <= (int)'z'; i++ ) if ( visited[i] == 0 ) {
		if( not dfs( i ) ) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	
	reverse( result.begin(), result.end() );
	cout << result << endl;
	
	
	
	return 0;
}
