
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We divide the sequence in distinct elements, and we store the occurences
 * of each element.  We sort the numbers and then we scan the array keeping 
 * track of how many pairs we passed. When we have found the first element 
 * we scan the array one time again to choose the second.
 * Complexity: O(N logN) int time and O(N) in space, assuming that hash_table
 * is working in O(1).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector<int> a;
unordered_map <int,int> table;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n >> k;
	int tmp;
	for(int i =0; i<n; i++) {
		cin >> tmp;
		table[tmp]++;
		if(table[tmp] == 1) a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	
	// First
	long long total = 0;
	int f;
	for(unsigned int i = 0; i < a.size(); i++) {
		f = table[a[i]];
		total += f;
		if( k <= total * n ) {
			cout << a[i] << ' ';
			k -= (total - f) * n;
			break;
		}
		
	}
	
	
	// Second
	total = 0;
	for(unsigned int i = 0; i < a.size(); i++) {
		total += table[a[i]];
		if( k <= total * f ) {
			cout << a[i];
			break;
		}
		
	}
	
	
	return 0;
}
