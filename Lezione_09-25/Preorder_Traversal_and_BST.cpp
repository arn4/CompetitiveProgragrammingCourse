
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is based on the observation that if [a,b) can represent
 * a BST, there must exists a k ( a+1 <= k <= b ) such that [a+1, k) and
 * [k,b) are both BST and the maximum key in the first interval is greater 
 * than A[a], while the minimum in the second one is smaller than A[a].
 * We can use a recursive function to compute if a given interval is a BST,
 * the maximum and the minimum. 
 * We note that k must be the next greater element of a, otherwise the BST
 * property is violated. So we can precompute the NGE as we did in the past
 * problem.
 * The overall complexity is O( N ) in space and O( T*N ) in time.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T, N;
stack < pair<int, int> > S;
int A[MAXN], nle[MAXN];

// Check if [a,b) can be a BST.
// return: ( is_a_BST, (min, max) )
pair< bool, pair< int, int > > check_BST( int a, int b ) {
	
	// If it is a not valid interval
	if( b <= a ) return make_pair( true, make_pair( INT_MAX, INT_MIN ) );
	
	// Single element
	if( a + 1 == b ) {
		return make_pair( true, make_pair( A[a], A[a] ) );
	}
	
	
	auto left = check_BST( a + 1, nle[a] ), 
		 right = check_BST( nle[a] , b );
		 
	bool is_BST = left.first and 
					right.first and 
					left.second.second <= A[a] and
					right.second.first >= A[a];
	
	return make_pair( is_BST, make_pair( 
					  min( left.second.first, right.second.first) , 
					  max( left.second.second, right.second.second) ) );
}

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		for( int i = 0; i < N; i++ ) cin >> A[i];
		
		// Computing next larger element
		while( !S.empty() ) S.pop();
		S.push( make_pair( INT_MAX, N ) );
		
		for( int i = N - 1; i >= 0; i-- ) {
			
			while( !S.empty() and A[i] >= S.top().first ) S.pop();
			
			nle[i] = S.top().second;
			
			S.push( make_pair( A[i], i ) );
		}
		
		if( check_BST( 0, N ).first ) cout << 1 << endl;
		else cout << 0 <<endl;
	}
	
	return 0;
}
