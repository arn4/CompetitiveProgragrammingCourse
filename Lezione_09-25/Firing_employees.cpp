
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We compute all primes numbers that can be involved in the problem with
 * sieve of Erastone. We use a recursive function for scan the tree; one
 * paraemter of the function is the number of senior of the node, so we can
 * easy check if a node has to be fired.
 * The complexity is O( T*N ) in time and O( N ) in space, but theres a 
 * big costant factor because of the sieve.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int T;
bool not_prime[2*MAXN+1];
int N, fired;
vector <int> G[MAXN+1];

void fire( int v, int deep ) {
	for( auto u: G[v] ) {
		if( v != 0 and (not not_prime[ u + deep ] ) ) fired++;
		fire( u, deep + 1 );
	}
}


int main() {
	
	ios_base::sync_with_stdio(false);
	
	// Generate primes
	for( int i = 2; i <= 2*MAXN; i++ ) if( not not_prime[i] ) {
		for( int j = 2*i; j <= 2*MAXN; j += i ) 
			not_prime[j] = true; 
	}
	
	cin >> T;
	
	while( T-- ) {
		
		for( int i = 0; i <= N; i++ ) G[i].clear();
		fired = 0;
		
		cin >> N;
		
		int senior;
		for( int i = 1; i <= N; i++ ) {
			cin >> senior;
			G[senior].push_back( i );
		}
		
		fire( 0, 0 );
		cout << fired << endl;
	}
	
	return 0;
}
