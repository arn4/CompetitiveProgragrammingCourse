
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is conceptually the same as the one with priority queue,
 * but is using set.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T;
int N, K, a;
set < pair< int, int > > ms;
set< pair<int, int> >::iterator it;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N >> K;
		ms.clear();
		
		for( int i = 0; i < K - 1; i++ ) {
			cin >> a;
			ms.insert( make_pair( a, i ) );
		}
		
		
		for( int i = K - 1; i < N; i++ ) {
			cin >> a;
			ms.insert( make_pair( a, i ) );
			
			while( (*ms.rbegin()).second <= i - K ) ms.erase( --ms.end() );
			
			cout << (*ms.rbegin()).first << ' ';
		}
		
		
		cout << endl;
	}
	
	return 0;
}
