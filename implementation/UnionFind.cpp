
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* UNION FIND:
 * Implemamtation of Union-Find data structure. 
 * Heavily inspired by Competitive Programming 3.
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

int main() {
	UnionFind U = UnionFind(7);
	
	U.unionSets(0,1);
	U.unionSets(2,3);
	U.unionSets(0,2);
	
	cout<<U.findSet(3)<<' '<<U.findSet(1)<<endl;
	
	cout<<U.isSameSet(7,4)<<endl;
	
	U.unionSets(5,4);
	U.unionSets(6,4);
	U.unionSets(7,6);
	
	cout<<U.isSameSet(7,4)<<endl;
	
	U.unionSets(1,6);
	
	cout<<U.numOfSets()<<' '<<U.size(U.findSet(6));
}
