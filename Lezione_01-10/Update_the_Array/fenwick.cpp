
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
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> n >> u;
		RangeFenwick F = RangeFenwick( n );
		
		while( u-- ) {
			cin >> a >> b >> v;
			F.update( a+1, b+1, v );
		}
		
		cin >> q;
		
		while( q-- ) {
			cin >> a;
			cout << F.query( a+1, a+1 ) << endl;
		}
	}
	
	return 0;
}
