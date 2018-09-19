
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * 
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T;
int N, K, a;
deque <pair < int, int > > dq;


int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N >> K;
		dq.clear();
		
		for( int i = 0; i < K - 1; i++ ) {
			cin >> a;
			while( !dq.empty() && dq.back().first <= a ) dq.pop_back();
			dq.push_back( make_pair( a, i ) );
		}
		
		for( int i = K - 1; i < N; i++ ) {
			cin >> a;
			while( !dq.empty() && dq.back().first <= a ) dq.pop_back();
			dq.push_back( make_pair( a, i ) );
			
			// Remove top elements that are't anymore in the subarray
			while( dq.front().second <= i - K ) dq.pop_front();
			
			cout << dq.front().first << ' ';
		}
		
		cout << endl;
	}
	
	return 0;
}
