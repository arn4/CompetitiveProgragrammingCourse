
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is the implementation of the one discussed at lecture.
 * Complexity is O( n + u + q ) in time and O( n ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int T;
int n, u, q;
int a, b, v;
int A[MAXN+1];

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> n >> u;
		
		fill( A, A + n + 1, 0 );
		
		while( u-- ) {
			cin >> a >> b >> v;
			A[a] += v;
			A[b+1] -= v;
		}
		
		for( int i = 1; i < n; i++ ) A[i] += A[i-1];
		
		cin >> q;
		
		while( q-- ) {
			cin >> a;
			cout << A[a] << endl;
		}
	}
	
	return 0;
}
