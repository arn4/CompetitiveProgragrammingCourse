
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is a simply implementation of Kadane's Algorithm, as
 * presented at lesson.
 * The solution complexity is O( T*N ) in time and O( 1 ) in memory.
*/


#include <bits/stdc++.h>

using namespace std;

int T, N;
int a, max_sum, partial;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		max_sum = -101;
		partial = 0;
		
		while( N-- ) {
			cin >> a;
			if( partial >= 0 ) {
				partial += a;
			} else {
				partial = a;
			}
			max_sum = max( max_sum, partial );
		}
		
		cout << max_sum << endl;
	}
	
	
	return 0;
}
