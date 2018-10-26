
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution implement a segment tree with lazy update on the array A
 * for answering to queries on intervals efficently. Circular queries that 
 * are handled slpittting in two queries on the array.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

											 
class SegmentTree {
	private:
		int sz; // Size of the array ( NOT the size of st )
		vector <long long> st; // somme
		vector <long long> lazy; // ausialr tree for lazy propagation
		
		// Function for moving between nodes
		int left( int i ) {
			return 2*i + 1;
		}
		
		int right( int i ) {
			return 2*i + 2;
		}
		
		int parent( int i ) {
			return (i - 1 ) / 2;
		}
		
		// propagate the laziness of the node
		void propagate_lazy( int p, int L, int R ) {
			if( lazy[p] == 0 ) return;
			// Update this node
			st[p] += lazy[p];
			
			// Propagate if it isnt a leaf 
			if( L != R) {
				lazy[ left(p) ] += lazy[p];
				lazy[ right(p) ] += lazy[p];
			}
			
			// Reset the actual node
			lazy[p] = 0;
		}
		
		
		// Build the tree given initial vector
		void build( int p, int L, int R, const vector<long long>& initial ) {
			if( L == R ) { // It is a leaf
				st[p] = initial[L];
			} else {
				// Building children
				build( left( p ), L, ( L + R ) / 2,  initial );
				build( right( p ), ( L + R ) / 2 + 1, R,  initial );
				st[p] = min( st[ left(p) ], st[ right(p) ]);
			}
		}
		
		
		// Update the range [i, j] with the associative operation
		long long update( int p, int L, int R, int i, int j, long long v ) {
		
			propagate_lazy( p, L, R );
		
			if( i > R or j < L ) return st[p]; // No intersection
			if( L >= i and R <= j ) {  // Contained
				st[p] +=  v;
				if( L != R ) { // If it isnt a leaf
					lazy[ left(p) ] += v;
					lazy[ right(p) ] += v;
				}
				return st[p];
			} 
			
			// Updating this node
			st[p] = min( update( left( p ), L, ( L + R ) / 2, i, j, v ),
						 update( right( p ), ( L + R ) / 2 + 1, R, i, j, v ) );
						 
			return st[p];
		}
		
		// Internal query, it has L and R as parametres
		long long query( int p, int L, int R, int i, int j ) {

			propagate_lazy( p, L, R );
				
			if( i > R or j < L ) // No intersection
				return LLONG_MAX; 
			if( i <= L and R <= j ) // Contained
				return st[p]; 
			
			return min( query( left( p ), L, ( L + R ) / 2, i, j ),
						query( right( p ), ( L + R ) / 2 + 1, R, i, j ) );
		}
		
	public:
		// Build the segment tree given 0-indexed initial
		SegmentTree( const vector <long long>& initial) {
			sz = initial.size();
			st.assign( initial.size() * 4, 0); // enough space
			lazy.assign( initial.size() * 4, 0 );
			
			build( 0, 0, sz - 1, initial );
		}
		
		long long update( int i, int j, long long v ) { return update( 0, 0, sz - 1, i, j, v ); }
		
		long long query( int i, int j ) { return query( 0, 0, sz - 1, i, j ); }
};

int n, m;
bool q;
vector <long long> A;
string line;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	A.resize( n );
	for( int i = 0; i < n; i++ ) cin >> A[i];
	auto RMQ = SegmentTree( A );
	
	cin >> m;
	cin.ignore(); // skip endl in the last read line
	while( m-- ) {
		getline( cin, line );
		stringstream stream(line);
		vector <long long> data;
		long long tmp;
		while( stream >> tmp) {
			data.push_back( tmp );
		}
		
		if( data.size() == 3 ) {
			if ( data[1] < data[0] ) {
				RMQ.update( 0, data[1], data[2] ); 
				RMQ.update( data[0], A.size() - 1, data[2] ); 
			} else 
				RMQ.update( data[0], data[1], data[2] );
		} else {
			if ( data[1] < data[0] ) {
				cout << min( RMQ.query( 0, data[1] ), RMQ.query( data[0] , A.size() - 1 ) ) << '\n';
			} else 
				cout << RMQ.query( data[0], data[1]) << '\n';
		}
	}
	
	return 0;
}
