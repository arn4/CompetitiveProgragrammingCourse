

/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is the one discussed in class: it's the implementation of
 * merge sort, but we count the number of inversion while merging.
 * Complexity is: O( T*NlogN ) in time and O( N ) in space.
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int T, N;
int A[MAXN];

// Count inversion in the array [a,b)
long long inversion_count( int a, int b ) {
	if( a + 1 == b ) return 0;
	
	int mid = ( a + b ) / 2;
	long long result = inversion_count( a, mid ) + inversion_count( mid, b );
	int i = a, j = mid;
	
	vector <int> ordered;
	
	while( i != mid and j != b ) {
		if( A[j] < A[i] ) {
			ordered.push_back( A[j] );
			result += (long long)(mid - i);
			j++;
			continue;
		}

		
		while( A[i] < A[j] and i != mid) {
			ordered.push_back( A[i] );
			i++;
		}
	}
	
	if( i == mid ) 
		while( j != b ) {
			ordered.push_back( A[j] );
			j++;
			
		}
	if( j == b )
		while( i != mid ) {
			ordered.push_back( A[i] );
			i++;
		}
		
	for( int k = a; k < b; k++ ) 
		A[k] = ordered[ k-a ];
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		for( int i = 0; i < N; i++ )
			cin >> A[i];
			
		cout << inversion_count( 0, N );
		
		if( T != 0 ) cout << endl;
		
		
	}
	
}
