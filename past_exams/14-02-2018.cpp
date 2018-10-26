
#include <bits/stdc++.h>

using namespace std;

/* SHORTCUTS */
#define forn(i, n) for ( int i = 0; i < int(n); i++ )
#define pb( a ) push_back( a )
#define all( a ) (a).begin(), (a).end()
#define st first
#define nd second
#define mp( a, b ) make_pair( a, b )

/* CONSTANT */
const int INF = int(pow(2, 31) - 1);

#define MAXN 100000

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

int n;
int A[MAXN];
long long ans;

int main() {
	/* FILE READ */
	//freopen ("input.txt","r",stdin);
	//freopen("output", "w", stdout);
	
	// Fast cin and cout
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	Fenwick cnt = Fenwick( n );
	Fenwick pairs = Fenwick( n );
	
	
	forn( i, n ) {
		cin >> A[i];
		cnt.update( A[i], 1 );
		pairs.update( A[i], cnt.query( A[i] - 1 ) );
		ans += pairs.query( A[i] - 1);
	}
	
	cout << ans << endl;
	
	
	
}


