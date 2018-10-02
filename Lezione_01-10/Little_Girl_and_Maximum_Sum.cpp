
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * This is the implementation of the solution presentsded at lecture.
 * Complexity: O( N + Q ) in time, O( N ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int N, Q;
int A[MAXN];
int f[MAXN+1];
long long result;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> N >> Q;
	
	for( int i = 0; i < N; i++ ) cin >> A [i];
	
	for( int i = 0; i < Q; i++ ) {
		int a,b;
		cin >> a >> b;
		f[a]++;
		f[b+1]--;
	}
	
	for( int i = 1; i <= N; i++ ) f[i] += f[i-1];
	
	sort( f + 1, f + ( N+1 ) );
	sort( A, A + N );
	
	for( int i = 0; i < N; i++ ) result += ( (long long)A[i] )*( (long long)f[i+1] );
	
	cout << result << endl;
	
	return 0;
}
