
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* BINARY INDEXED TREE
 * 
 * 
*/


#include <bits/stdc++.h>

using namespace std;

class Fenwick {
	private:
		vector <int> ft;
		
	public:
		Fenwick() {} // Needed for the RangeFenwick, it is default constructor
	
		Fenwick( int n ) {
			ft.assign( n + 1, 0 );
		}
		
		int query( int k ) {
			int ans = 0;
			
			while( k != 0 ) {
				ans += ft[ k ];
				k -= k & (-k);
			}
			
			return ans;
		}
		
		void update( int k, int v ) {
			while( k < ft.size() ) {
				ft[k] += v;
				k += k & (-k);
			}
		}
};

class RangeFenwick {
	private:
		Fenwick F1, F2;
		
		int partial_sum( int k ) {
			return F1.query( k ) * k - F2.query( k );
		}
		
	public:
	
		RangeFenwick( int n ) {
			// The +1 after n is need to avoid problems when update( r+1, v )
			F1 = Fenwick( n + 1 );
			F2 = Fenwick( n + 1 );
		}
		
		
		// query of the range [l,r]
		int query( int l, int r ) {
			return partial_sum( r ) - partial_sum( l - 1 );
		}
		
		// add v to all [l,r]
		void update( int l, int r, int v ) {
			F1.update( l, v );
			F1.update( r + 1, -v );
			F2.update( l, v * (l - 1) );
			F2.update( r + 1, -v * r );
		}
		
};

int main() {
	
	// Test Fenwick
	Fenwick F = Fenwick( 8 );
	
	F.update( 1, 3 );
	F.update( 2, 2 );
	F.update( 3, -1 );
	F.update( 4, 5 );
	F.update( 5, 7 );
	F.update( 6, -3 );
	F.update( 7, 2 );
	F.update( 8, 1 );
	
	cout << F.query( 7 ) << endl;
	cout << F.query( 3 ) << endl;
	
	F.update( 3, 3 );
	
	cout << F.query( 3 ) << endl;
	
	// Test RangeFenwick
	RangeFenwick RF = RangeFenwick( 8 );
	
	RF.update( 1, 8, 5);
	RF.update( 2, 7, 4);
	RF.update( 3, 6, 3);
	RF.update( 4, 5, 2);
	
	cout << RF.query( 1, 8 ) << endl;
	cout << RF.query( 5, 5 ) << endl;
	
	RF.update( 4, 4, 100 );
	
	cout << RF.query( 4, 7 ) << endl;
	
}
