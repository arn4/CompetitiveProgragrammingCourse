
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SEGMENT TREE
 * Implementation of a template-based SegmentTree with lazy propagation.
 * It supports both range update and queries.
 * !! Not tested if the operation doesnt commute. !!
*/


#include <bits/stdc++.h>

using namespace std;


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


/*** TESTING ***/

int sum( const int& a, const int& b ) { return a + b; }
int t_sum( unsigned int t, const int& a ) { return (int)t*a; }

int main() {
	vector<int> A = { 0,0,0,0,0,0,0,0,0,0,0,0};

	auto RSQ = SegmentTree<int, sum, t_sum>( A, 0 );
	
	RSQ.update( 0, 5, 3 );
	cout << RSQ.query( 3, 11) << endl;
	RSQ.update( 2, 6, -5 );
	cout << RSQ.query( 3, 11) << endl;
	
}
