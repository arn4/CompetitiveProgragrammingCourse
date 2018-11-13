
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * This is the implementation of the solution presentsded at lecture.
 * Complexity: O( size(S) + Q ) in time, O( size(S) ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

string S;
int pf[MAXN+1];
int Q, a, b;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> S;
	S.push_back( 't' );
	
	for( int i = 0; i < S.size(); i++ ) {
		pf[i+1] = pf[i] + ( S[i] == S[i+1] ? 1 : 0 );
	}
	
	cin >> Q;
	
	while( Q-- ) {
		cin >> a >> b;
		
		cout << pf[b-1] - pf[a-1] << endl;
	}
	
	return 0;
}
