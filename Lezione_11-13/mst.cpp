
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

class UnionFind {
	private:
		vector <int> parent; // Parent of a node
		vector <int> rank; // upper bound of the height of the tree
		vector <int> elements; // number of elements in the set
		int numSet;
		
	public:
		
		UnionFind(int N = 0) {
			numSet = N;
			elements.assign(N, 1);
			rank.assign(N, 0);
			parent.assign(N, 0);
			for(int i = 0; i<N; i++) parent[i]=i;
			
		}
		
		int findSet(int n) {
			if(parent[n] == n) 
				return n;
			return parent[n] = findSet(parent[n]);
		}
		
		bool isSameSet(int n, int m) {
			return (findSet(n) == findSet(m));
		}
		
		void unionSets(int n, int m) {
			n = findSet( n );
			m = findSet( m );
				
			if(isSameSet(n,m)) return;
			
			numSet--;
			
			if(rank[n] < rank[m]) {
				elements[m] += elements[n];
				elements[n] = 0;
				parent[n] = m;
			} else {
				elements[n] += elements[m];
				elements[m] = 0;
				parent[m] = n;
				
				if(rank[n] == rank[m]) 
					rank[n]++;
			}
		}
		
		int size(int n) {
			return elements[findSet(n)];
		}
		
		int numOfSets() {
			return numSet;
		}
};

struct Edge{
	int u,v;
	long long w;
	
	Edge( int u = 0, int v = 0, long long w = 0 ) :
		u(u),
		v(v),
		w(w) {}	
};

bool operator <( const Edge& a, const Edge& b ) {
	return a.w < b.w;
}

int n,m;
long long ans;
vector<Edge> E;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n >> m;
	E.resize( m );
	int a, b, c;
	for( int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		E[i] = Edge( a - 1 , b - 1, c );
	}
	
	sort( E.begin(), E.end() );
	auto UF = UnionFind( n );
	for( auto e: E ) {
		if( not UF.isSameSet( e.u, e.v ) ) {
			UF.unionSets( e.v, e.u );
			ans += e.w;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
