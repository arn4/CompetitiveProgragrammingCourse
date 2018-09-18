
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We add all the odd numbers and we subtract all the even. We return
 * the distance between the expected value and the calculated one.
 * The time complexity is O( T*N ), the space complexity is O(1), but 
 * potentially using less bit compared to adding all the elements, since
 * to the partial sum is always between -N and N.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int T, N;
int sum, a;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		sum = 0;
		
		for( int i = 0; i < N - 1; i++ ) {
			cin >> a;
			if( a % 2 == 1 ) sum += a;
			else sum -= a;
		}
		
		int expected_sum = ( N % 2 == 1 ? N / 2 + 1 : -N / 2 );
		
		cout << max( expected_sum, sum ) - min( expected_sum, sum ) << endl;
	}
	
	return 0;
}
