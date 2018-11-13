
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * First of all we compress the coordinates of the segments, mantaining 
 * the order, but having all the values between 1 and 2*n. Now we sort
 * the segments in decreasing order of left extreme. Scanning the segments
 * in this order guarantee that left extreme of all passed ones is righter
 * than actual segment. To count how many elements are cointained in the
 * actual segment we simply have to count how many passed segments end
 * before than actual. This can be done we a trivial application of Fenwick
 * tree.
 * Complexity: O( N*logN ) time and O( N ) space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int T;

#define MAXN 200000

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
			while( (unsigned int )k < ft.size() ) {
				ft[k] += v;
				k += k & (-k);
			}
		}
};

struct Segment{
	int l, r, index;
	
	Segment( int l_ = 0, int r_ = 0) {
		l = l_;
		r = r_;
	}
};


bool operator < ( const Segment& a, const Segment& b ) {
	return a.l > b.l;
}


int n;
int l, r;
pair<int, int> cc[2*MAXN];
Segment seg[MAXN];
int ans[MAXN];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for( int i = 0; i < n; i++) {
		cin >> l >> r;
		cc[2*i] = make_pair( l, 2*i );
		cc[2*i+1] = make_pair( r, 2*i+1 );
	}
	
	sort( cc, cc + 2*n );
	
	// Saving compressed segments
	for( int i = 0; i < 2*n; i++ ) {
		seg[cc[i].second/2].index = cc[i].second/2;
		if( cc[i].second % 2 == 1 ) {
			seg[cc[i].second/2].r = i + 1;
		} else {
			seg[cc[i].second/2].l = i + 1;
		}
	}
	
	sort( seg, seg + n );
	auto F = Fenwick( 2*n );
	for( int i = 0; i < n; i++ ) {
		//cout << seg[i].r << ' ' << seg[i].l << ' ' << F.query( seg[i].r ) << endl;
		ans[seg[i].index] = F.query( seg[i].r );
		F.update( seg[i].r , 1 );
	}
	
	for(int i = 0; i < n; i++ ) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}
