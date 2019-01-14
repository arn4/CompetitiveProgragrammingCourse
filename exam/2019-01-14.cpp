
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * 
 * 
*/


#include <bits/stdc++.h>

using namespace std;

class Fenwick {
	private:
		vector <int> ft;
		
	public:
	
		Fenwick( int n = 0 ) {
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

struct Query{
	int i, j, X, ans;
	
	Query(int i_ = 0, int j_ = 0, int X_ = 0) {
		i = i_;
		j = j_;
		X = X_;
	}
};



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	int n, m;
	vector<int> A;
	vector<vector<int>> GA;
	vector<vector<int>> GQ;
	vector<Query> Q;
	
	cin >> n >> m;
	
	A.resize(n);
	GA.resize(n+1);
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		GA[A[i]].push_back(i);
	}
	
	Q.resize(m);
	GQ.resize(n+1);
	for(int i = 0; i < m; i++) {
		cin >> Q[i].i >> Q[i].j >> Q[i].X;
		Q[i].X = min(Q[i].X, n);
		GQ[Q[i].X].push_back(i);
	}
	
	auto FT = RangeFenwick(n);
	for(int i = 0; i <= n; i++) {
		//cout << "Processing " << i << endl;
		for(auto j: GA[i]) {
			//cout << "	Inserting " << j << ": " << A[j] << endl;
			FT.update(j+1, j+1, 1);
		}
		for(auto j: GQ[i]) {
			//cout << "	Answering " << j << ": " << Q[j].i << ' ' << Q[j].j << ' ' << Q[j].X << ' '<< endl;
			Q[j].ans = FT.query(Q[j].i+1, Q[j].j+1);
		}
	}
	
	for(auto& q: Q) 
		cout << q.ans << endl;
	
	return 0;
}
