
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The idea is to divide the cubes such that the number of different cubes 
 * in each set differs at most by 1.
 * Complexity is O(N) both in space and time, assuming that hash table 
 * operations are working in O(1).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, ans;
unordered_multiset <int> first, second;
unordered_map <int,int> cont;
int oo, to;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	a.resize(2*n);
	for(int i = 0; i < 2*n; i++ ) {
		cin >> a[i];
		cont[a[i]]++;
		if(cont[a[i]] == 2 ) {
			oo--;
			to++;
			
		} else if( cont[a[i]] == 1) {
			oo++;
		}
	}
	
	// Calculate the number
	cout << (oo/2 + oo%2 + to) * (oo/2 + to) << endl;
	
	ans.resize(2*n);
	for(int i = 0; i < 2*n; i++ ) if(cont[a[i]] > 1) {
		if( first.find(a[i]) == first.end() ) {
			ans[i] = 1;
			first.insert(a[i]);
		} else if ( second.find(a[i]) == second.end() ) {
			ans[i] = 2;
			second.insert(a[i]);
		} else {
			ans[i] = -1;
		}
	}
	
	
	for(int i = 0; i < 2*n; i++ ) {
		if(cont[a[i]] == 1) {
			if( int(first.size()) < oo/2 + oo%2 + to) {
				ans[i] = 1;
				first.insert(a[i]);
			} else {
				ans[i] = 2;
			}
		}
	}
	
	for(int i = 0; i < 2*n; i++ ) if (ans[i] == -1) {
		if( int(first.size()) < n ) {
			ans[i] = 1;
			first.insert(a[i]);
		} else {
			ans[i] = 2;
		}
	}
	
	for( auto i: ans) cout << i << ' ';
	
	
	return 0;
}
