
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We try all the possible subarrays from left to right and we use a 
 * priority queue to keep track of the maximum element efficently.
 * If the top element is out of the range, it will never be usefull again,
 * so we discard it.
 * Since that operations on priority_queue take logN, the
 * overall time complexity is O ( T*N*logN ) in time and O( N ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T;
int N, K, a;
priority_queue < pair< int, int > > pq;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N >> K;
		// Clearing priority queue
		while( !pq.empty() ) pq.pop();
		
		for( int i = 0; i < K - 1; i++ ) {
			cin >> a;
			pq.push( make_pair( a, i ) );
		}
		
		for( int i = K - 1; i < N; i++ ) {
			cin >> a;
			pq.push( make_pair( a, i ) );
			
			// Remove top elements that are't anymore in the subarray
			while( pq.top().second <= i - K ) pq.pop();
			
			cout << pq.top().first << ' ';
		}
		
		
		cout << endl;
	}
	
	return 0;
}
