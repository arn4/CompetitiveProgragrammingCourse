
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We can easily precompute all the f() we need in linear time, using an
 * hash table ( unordered_map ). Now the problem is reduced two count 
 * the inversion between pre and suf, that can be done using a Fenwick tree.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

class Fenwick {
	private:
		vector <int> ft;
		
	public:
	
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
int a[MAXN], pre[MAXN], suf[MAXN];
unordered_map<int,int> lf, rg;
long long ans;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for( int i = 0; i < n; i++ ) cin >> a[i];
	
	for( int i = 0; i < n; i++ ) {
		lf[a[i]]++;
		pre[i] = lf[a[i]];
	}
	
	for( int i = n - 1; i >= 0; i-- ) {
		rg[a[i]]++;
		suf[i] = rg[a[i]];
	}
	
	Fenwick F = Fenwick( n + 1 );
	
	for( int i = n-1; i >= 0; i-- ) {
		ans += F.query( pre[i] - 1 );
		F.update( suf[i], 1 );
	}
	
	cout << ans << endl;
	
	return 0;
}
