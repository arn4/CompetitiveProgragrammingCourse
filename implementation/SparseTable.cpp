
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SPARSE TABLE:
 * Template based implementation of a Sparse Table.
 * The file contain also an implementation of SparseTable optimized for
 * RMQ, with O(1) query.
 * Note: must define table_size!
 * Note: there could be problem in allocating memory in real contest because
 * of the dynamic allocation of the class (ie: table of size > 1M doesnt
 * work on my PC). You should consider allocating the table as global variable.
*/


#include <bits/stdc++.h>

using namespace std;



const int table_size = 100; 
const int log_table_size = 7;

template < typename T, // Type of the elements
		   T associative(const T&, const T&) > // Associative operation 
class SparseTable {
	private:
		T SpT[table_size][log_table_size]; // Container
		T identity;
		unsigned int sz;
	public:
		SparseTable( const vector<T>& A_, T identity_ ) {
			// Set the identity element
			identity = identity_;
			
			// Build the array
			sz = A_.size();
			for( unsigned int i = 0; i < sz; i++ ) {
				SpT[i][0] = A_[i];
			}
			
			// Precalculate all elements
			for( int j = 1; (1<<j) <= sz; j++  ) // 2^j <= n
				for( unsigned int i = 0; i + (1<<j) - 1 < sz; i++ ) // i + 2^j<= n
					SpT[i][j] = associative( SpT[i][j-1], SpT[i + (1<<(j-1))][j-1] );
				
		}
		
		T query( int a, int b ) {
			T ans = identity;
			
			// Decompose the range in poweras of 2
			for( int j = log_table_size; j >= 0; j-- ) 
				if ((1 << j) <= b - a + 1) {
					ans = associative( ans, SpT[a][j] );
					a += 1 << j;
				}
			
			return ans;
		}
};


/* This implementation stores the elements in a separated array. 
 * It's a Range Minimum Query, but it's easy to switch to Maximum
 */

class RMQ {
	private:
		vector<int> A; // Array of the elements
		int SpT[table_size][log_table_size]; // Sparse Table of the index
	public:
		RMQ( const vector<int>& A_ ) {
			
			// Build the array
			A.assign( A_.size(), 0 );
			for( unsigned int i = 0; i < A.size(); i++ ) {
				A[i] = A_[i];
				SpT[i][0] = i;
			}
			
			// Precalculate all elements
			for( int j = 1; (1<<j) <= A.size(); j++  ) // 2^j <= n
				for( unsigned int i = 0; i + (1<<j) - 1 < A.size(); i++ ) { // i + 2^j<= n
					
					if( A[ SpT[i][j-1] ] < A[ SpT[ i+(1<<(j-1)) ][j-1] ] ) 
						SpT[i][j] = SpT[i][j-1]; 
					else 
						SpT[i][j] = SpT[ i+(1<<(j-1)) ][j-1];
				}
		}
		
		// Return the index
		int query( int a, int b ) {
			int k = floor( log( (double)( b - a + 1 ) ) / log( 2.0 ) );
			
			if ( A[SpT[a][k]] <= A[SpT[b-(1<<k)+1][k]]) return SpT[a][k];
			else return SpT[b-(1<<k)+1][k];

		}
};

/****TESTING****/

int sum( const int& a, const int& b ) { return a + b; }


int main() {
	
	ios_base::sync_with_stdio(false);
	
	//                0  1  2  3  4  5  6  7  8  9 10  11   12
	vector<int> A = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, -3, -20 };
	
	RMQ mini = RMQ( A );
	auto ST = SparseTable< int, sum >( A, 0 );

	cout << mini.query( 0, 3 ) << endl;
	cout << mini.query( 7, 9 ) << endl;
	cout << mini.query( 4, 8 ) << endl;
	cout << mini.query( 11, 12 ) << endl;
	cout << mini.query( 6, 11 ) << endl;

	cout << ST.query( 0, 3 ) << endl;
	cout << ST.query( 7, 9 ) << endl;
	cout << ST.query( 4, 8 ) << endl;
	cout << ST.query( 11, 12 ) << endl;
	cout << ST.query( 6, 11 ) << endl;
	
}
