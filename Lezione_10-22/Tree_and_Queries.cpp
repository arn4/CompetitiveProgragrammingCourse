
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We can reduce the problem from a tree to an array with Euler tour. Every
 * sub-tree is now a range of an array, so we can use Mo's Algorithm to
 * answer queries.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int n, q;

int C[MAXN+1];
vector<int> G[MAXN+1];
int linear[MAXN+1];
int L[MAXN+ 1], R[MAXN+1];

struct Query {
	int a, b, k;
	int index;
	long long ans;
	
	Query( int v = 0, int k_ = 0, int i_ = 0 ) {
		a = L[v];
		b = R[v];
		k = k_;
		index = i_;
		ans = 0;
	}
	
	//Query( int v = 0, int k = 0, int i = 0 ):v(v), k(k), index(i), ans(0) {}
};

bool operator <(const Query& x, const Query& y ) {
	int bx = x.a / sqrt( n ), by = y.a / sqrt( n );
	if( bx == by ) return x.b < y.b;
	return bx < by;
}

bool i_order(const Query& x, const Query& y ) {
	return x.index < y.index;
}

int t = 0;
bool visited[MAXN+1];
void linearize( int v ) {
	visited[v] = true;
	
	linear[t] = v;
	L[v] = t;
	t++;
	for( auto u: G[v] ) if( not visited[u] ) linearize( u );
	R[v] = t-1;
}

vector<Query> Q;
int a, b; // Temp variables to read input
int K[MAXN+1];
int result[MAXN+1];

void add( int v ) {
	K[C[v]]++;
	result[ K[C[v]] ]++;
}

void remove( int v ) {
	result[ K[C[v]] ]--;
	K[C[v]]--;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n >> q;
	for( int i = 1; i <= n; i++ ) cin >> C[i];
	
	// Read th graph
	for( int i = 0; i < n - 1; i++ ) {
		cin >> a >> b;
		G[a].push_back( b );
		G[b].push_back( a );
	}
	
	// Linearize the tree
	linearize( 1 );
	
	// Read the queries
	Q.resize( q);
	for( int i = 0; i < q; i++ ) {
		cin >> a >> b;
		Q[i] = Query( a, b, i );
	}
	
	sort( Q.begin(), Q.end() );
	
	a = 0, b = 0; //Estremi dell'intervallo precedente
	K[ C[1] ] = 1;
	result[ 1 ] = 1;
	for( auto& p: Q ) {
		if( b < p.b ) {
			while( b != p.b ) {
				b++;
				add( linear[b] );
			}
		}
		if( a > p.a ) {
			while( a != p.a ) {
				a--;
				add( linear[a] );
			}
		}
		if( a < p.a ) {
			while( a != p.a ) {
				remove( linear[a] );
				a++;
			}
		}
		if( b > p.b ) {
			while( b != p.b ) {
				remove( linear[b] );
				b--;
			}
		}
		
		p.ans = result[p.k];
	}
	
	sort( Q.begin(), Q.end(), i_order );
	
	for( auto& p: Q ) cout << p.ans << endl;
	
	return 0;
}
