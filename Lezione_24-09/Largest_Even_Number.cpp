
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We read a number as a string, then we sort it. We scan the sorted 
 * array to find the smallest even digit. We move it at the end of the 
 * array. If there is no even digit, we do nothing.
 * Complexity is O( T*NlogN ) in time and O( N ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int T;
string S;


int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> S;
		sort( S.begin(), S.end() );
		
		char c = S[0];
		for( int i = 0; i < S.size(); i++ ) {
			// ASCII code of even digit is even
			if( ((int) S[i]) % 2 == 0 ) {
				c = S[i];
				S.erase( i, 1 );
				break;
			}
		}
		
		reverse( S.begin(), S.end() );

		if( (int)c % 2 == 0 ) 
			S.push_back( c );
		
		cout << S << endl;
	}
	
	return 0;
}
