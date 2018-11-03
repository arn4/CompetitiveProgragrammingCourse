/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution uses a modiefied version of BIT, that supports query and
 * update on ranges, as described here: https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
 * The complexity is O( T*(U + Q)logN ) in time and O( N ) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int T;
int n, u, q;
int a, b, v;

template <typename T, // Type of the elements 
		  T associative(const T&, const T&), // Associative operation
		  T t_associative( unsigned int t, const T& e) > // Multiple associative												 
class SegmentTree {
	private:
		int sz; // Size of the array ( NOT the size of st )
		vector <T> st; // 0 based segment-tree
		vector <T> lazy; // ausialr tree for lazy propagation
		T identity; // Identity element for the associative operation
		
		
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
			if( lazy[p] == identity ) return;
			// Update this node
			st[p] = associative( st[p], t_associative(R - L + 1, lazy[p] ) );
			
			// Propagate if it isnt a leaf 
			if( L != R) {
				lazy[ left(p) ] = associative( lazy[ left(p) ], lazy[p] );
				lazy[ right(p) ] = associative( lazy[ right(p) ], lazy[p] );
			}
			
			// Reset the actual node
			lazy[p] = identity;
		}
		
		
		// Build the tree given initial vector
		void build( int p, int L, int R, const vector<T>& initial ) {
			if( L == R ) { // It is a leaf
				st[p] = initial[L];
			} else {
				// Building children
				build( left( p ), L, ( L + R ) / 2,  initial );
				build( right( p ), ( L + R ) / 2 + 1, R,  initial );
				st[p] = associative( st[ left(p) ], st[ right(p) ] );
			}
		}
		
		
		// Update the range [i, j] with the associative operation
		void update( int p, int L, int R, int i, int j, T v ) {
		
			propagate_lazy( p, L, R );
		
			if( i > R or j < L ) return ; // No intersection
			if( L >= i and R <= j ) {  // Contained
				st[p] = associative( st[p], t_associative(R - L + 1, v ) );
				if( L != R ) { // If it isnt a leaf
					lazy[ left(p) ] = associative( lazy[ left(p) ], v );
					lazy[ right(p) ] = associative( lazy[ right(p) ], v );
				}
				return;
			} 
			
			int int_len; // Lenght of the intersection
			if ( L <= i and j <= R ) int_len = j - i + 1; // Contained
			else if( L <= j and j <= R ) int_len = j - L + 1; // Left intersection
			else  int_len = R - i + 1; // Right intersection

			
			// Updating this node
			st[p] = associative( st[p], t_associative( int_len, v ) );
			
			update( left( p ), L, ( L + R ) / 2, i, j, v );
			update( right( p ), ( L + R ) / 2 + 1, R, i, j, v );
		}
		
		// Internal query, it has L and R as parametres
		T query( int p, int L, int R, int i, int j ) {

			propagate_lazy( p, L ,R );
				
			if( i > R or j < L ) // No intersection
				return identity; 
			if( i <= L and R <= j ) // Contained
				return st[p]; 
			
			return associative( query( left( p ), L, ( L + R ) / 2, i, j ),
								query( right( p ), ( L + R ) / 2 + 1, R, i, j ) );
		}
		
	public:
		// Build the segment tree given 0-indexed initial
		SegmentTree( const vector <T>& initial, T identity_ ) {
			identity = identity_;
			sz = initial.size();
			st.assign( initial.size() * 4, identity ); // enough space
			lazy.assign( initial.size() * 4, identity );
			
			build( 0, 0, sz - 1, initial );
		}
		
		void update( int i, int j, T v ) { return update( 0, 0, sz - 1, i, j, v ); }
		
		T query( int i, int j ) { return query( 0, 0, sz - 1, i, j ); }
};

int sum( const int& a, const int& b ) {
	return a + b;
}

int prod( unsigned int t, const int& a ) {
	return (int)t * a;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> n >> u;
		auto F = SegmentTree<int, sum, prod>( vector<int>( n, 0 ), 0 );
		
		while( u-- ) {
			cin >> a >> b >> v;
			F.update( a, b, v );
		}
		
		cin >> q;
		
		while( q-- ) {
			cin >> a;
			cout << F.query( a, a ) << endl;
		}
	}
	
	return 0;
}
