
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is a trivial implementation of Mo's Algorithm.
 * Add(i) can be perfomed increasing the result by 2*K[A[i]] + 1; remove
 * is analogous.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXK 1000000

int n, q;

struct Query {
	int a, b;
	int index;
	long long ans;
	
	Query( int a_ = 0, int b_ = 0, int i_ = 0 ) {
		a = a_;
		b = b_;
		index = i_;
		ans = 0;
	}
};

bool operator <(const Query& x, const Query& y ) {
	int bx = x.a / sqrt( n ), by = y.a / sqrt( n );
	if( bx == by ) return x.b < y.b;
	return bx < by;
}

bool i_order(const Query& x, const Query& y ) {
	return x.index < y.index;
}

int A[MAXK + 1];
vector<Query> Q;
int K[1000001];
long long result;

void add( int i ) {
	result += ( 2 * (long long)K[A[i]] + 1 ) * (long long )A[i];
	K[A[i]]++;
}

void remove( int i ) {
	result += ( (-2) * (long long)K[A[i]] + 1 ) * (long long )A[i];
	K[A[i]]--;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> n >> q;
	for( int i = 1; i <= n; i++ ) {
		cin >> A[i];
	}
	
	Q.resize( q );
	for( int i = 0; i < q; i++ ) {
		cin >> Q[i].a >> Q[i].b;
		Q[i].index = i;
		Q[i].ans = 0;
	}
	
	sort( Q.begin(), Q.end() );
	
	
	int a = 0, b = 0; //Estremi dell'intervallo precedente
	for( auto& p: Q ) {
		if( b < p.b ) {
			while( b != p.b ) {
				b++;
				add( b );
			}
		}
		if( a > p.a ) {
			while( a != p.a ) {
				a--;
				add( a );
			}
		}
		if( a < p.a ) {
			while( a != p.a ) {
				remove( a );
				a++;
			}
		}
		if( b > p.b ) {
			while( b != p.b ) {
				remove( b );
				b--;
			}
		}
		
		p.ans = result;
	}
	
	sort( Q.begin(), Q.end(), i_order );
	
	for( auto& p: Q ) cout << p.ans << endl;
	
	return 0;
}
