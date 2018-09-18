
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We simply search the maximum in every contiguous subarray of size k.
 * Time complexity is O( T*N^2 ), space complexity is O( N ).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T;
int N, K;
int A[MAXN];

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N >> K;
		
		for( int i = 0; i < N; i++ ) cin >> A[i];
		
		for( int i = 0; i <= N - K; i++ ) {
			int max_array = 0;
			for( int j = 0; j < K; j++ ) {
				max_array = max( max_array, A[i+j] );
			}
			cout << max_array << ' ';
		}
		
		cout << endl;
	}
	
	return 0;
}
